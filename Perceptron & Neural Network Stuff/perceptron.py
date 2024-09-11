import numpy as np

class Perceptron:
    def __init__(self, learning_rate=0.1, epochs=10):
        self.learning_rate = learning_rate
        self.epochs = epochs
        self.weights = None
        self.bias = None

    def step_function(self, x):
        return 1 if x >= 0 else 0

    def predict(self, X):
        linear_output = np.dot(X, self.weights) + self.bias
        return self.step_function(linear_output)

    def fit(self, X, y):
        n_samples, n_features = X.shape
        self.weights = np.zeros(n_features)
        self.bias = 0

        for epoch in range(self.epochs):
            print(f"Epoch {epoch+1}/{self.epochs}")
            for idx, x_i in enumerate(X):
                linear_output = np.dot(x_i, self.weights) + self.bias
                y_pred = self.step_function(linear_output)

                update = self.learning_rate * (y[idx] - y_pred)
                self.weights += update * x_i
                self.bias += update

            # Print the weights and bias after each epoch
            print(f"Weights: {self.weights}, Bias: {self.bias}")

    def evaluate(self, X, y):
        predictions = [self.predict(x) for x in X]
        accuracy = np.mean(predictions == y)
        return accuracy

# Generate random linearly separable data
def generate_data(n_samples=100):
    X = np.random.rand(n_samples, 2) * 10 - 5  # Random values between -5 and 5
    y = np.array([1 if x[0] * x[1] > 0 else 0 for x in X])  # Non-linear boundary (quadrants)
    return X, y

# Main function to run Perceptron
if __name__ == "__main__":
    X, y = generate_data(n_samples=50)
    
    perceptron = Perceptron(learning_rate=0.1, epochs=10)
    perceptron.fit(X, y)
    
    # Evaluate the Perceptron performance
    accuracy = perceptron.evaluate(X, y)
    print(f"Final Accuracy: {accuracy * 100:.2f}%")
