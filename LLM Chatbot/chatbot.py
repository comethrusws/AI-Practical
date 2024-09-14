import requests
import json
import os
from dotenv import load_dotenv

load_dotenv()
# huggingface API token
HF_TOKEN = os.getenv('HUGGINGFACE_TOKEN')

def chatbot(prompt):
    API_URL = "https://api-inference.huggingface.co/models/bigscience/bloom"
    
    headers = {
        "Authorization": f"Bearer {HF_TOKEN}",
        "Content-Type": "application/json"
    }
    #API request payload
    data = json.dumps({
        "inputs": f"Human: {prompt}\nAI:", 
        "parameters": {
            "max_new_tokens": 50,  # limit response size
            "temperature": 0.7,      # control randomness
            "top_p": 0.9,            # ensure diversity
            "do_sample": True        # enable sampling for creative responses
        }
    })

    try:
        response = requests.post(API_URL, headers=headers, data=data)
        if response.status_code == 200:
            result = response.json()
            if isinstance(result, list) and 'generated_text' in result[0]:
                generated_text = result[0]['generated_text'].strip()
                # extract AI's response by isolating the part after "AI:"
                ai_response = generated_text.split("AI:")[-1].strip()
                # ensure it doesn't contain further "Human:" or repeated prompts
                if "Human:" in ai_response:
                    ai_response = ai_response.split("Human:")[0].strip()
                return ai_response
            else:
                return "Error: Unexpected response format."
        else:
            return f"Error: {response.status_code}, {response.text}"
    except Exception as e:
        return f"Exception occurred: {str(e)}"

def main():
    print("Welcome to the BLOOM Chatbot!")
    print("Type 'quit' to exit the chat.")

    while True:
        user_input = input("You: ")        
        if user_input.lower() == 'quit':
            print("Goodbye!")
            break

        ai_response = chatbot(user_input)
        print(f"AI: {ai_response}")

if __name__ == "__main__":
    if not HF_TOKEN:
        print("Please set your Hugging Face token in the 'HF_TOKEN' variable.")
    else:
        main()
