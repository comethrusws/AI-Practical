import json
import random
import os

class Chatbot:
    def __init__(self, knowledge_base_file):
        with open(knowledge_base_file, 'r') as f:
            self.knowledge_base = json.load(f)

    def get_response(self, user_input):
        user_input = user_input.lower()

        if user_input == 'quit':
            return "Goodbye! It was nice talking to you."
        
        for topic, facts in self.knowledge_base.items():
            if topic in user_input:
                return f"Here's what I know about {topic}: {random.choice(facts)}"

        if 'hello' in user_input or 'hi' in user_input:
            return "Hello there! How can I help you today?"
        elif 'how are you' in user_input:
            return "I'm doing well, thank you for asking! How about you?"
        elif 'your name' in user_input:
            return "My name is SIMRIK. Nice to meet you!"
        else:
            topics = ", ".join(self.knowledge_base.keys())
            return f"I'm not sure about that. You can ask me about: {topics}."

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    # full path to the knowledge base file
    knowledge_base_path = os.path.join(script_dir, 'knowledge_base.json')
    
    print(f"Attempting to load knowledge base from: {knowledge_base_path}")
    
    try:
        chatbot = Chatbot(knowledge_base_path)
        print("Knowledge base loaded successfully.")
        print("Hello! I'm SIMRIK. You can ask me about various topics.")
        print("Type 'quit' to end the conversation.")

        while True:
            user_input = input("You: ")
            response = chatbot.get_response(user_input)
            print(f"SIMRIK: {response}")
            if user_input.lower() == 'quit':
                break
    except FileNotFoundError:
        print(f"Error: Could not find the knowledge base file at {knowledge_base_path}")
        print("Please make sure 'knowledge_base.json' is in the same directory as this script.")

if __name__ == "__main__":
    main()