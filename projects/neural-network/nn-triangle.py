import numpy as np
import matplotlib.pyplot as plt

# Network hyperparameters
LEARNING_RATE = 0.01       # Controls how much we adjust weights each iteration
                          # Lower values: more precise but slower learning
                          # Higher values: faster but may overshoot optimal weights

ITERATIONS = 10000        # Total number of training cycles
                         # Higher values allow more time to find optimal weights
                         # but increase training time

PRINT_COST_EVERY = 100   # Frequency of cost reporting during training
                         # Lower values give more frequent feedback but slow training

NUM_HIDDEN_LAYERS = 64   # Base number of neurons in the first hidden layer
                         # More neurons can capture more complex patterns
                         # but increase computational cost and risk of overfitting

# Architecture of hidden layers - number of neurons in each layer
# Each subsequent layer has fewer neurons, creating a "funnel" shape
# This helps reduce dimensionality as we approach the output
HIDDEN_LAYERS = [NUM_HIDDEN_LAYERS, NUM_HIDDEN_LAYERS//2, NUM_HIDDEN_LAYERS//4]

EPSILON = 1e-15          # Small constant added to prevent log(0) in cost calculation
                         # Helps avoid numerical instability

# Currently unused hyperparameters that could be implemented:
BATCH_SIZE = 32         # Size of mini-batches for gradient descent
                       # Smaller batches: more frequent updates, more noise
                       # Larger batches: more stable updates, more memory usage

MOMENTUM = 0.9         # Factor for momentum in gradient descent
                      # Higher values help escape local minima
                      # but may overshoot global minimum

L2_REG = 0.01         # L2 regularization strength
                      # Higher values reduce overfitting but may underfit
                      # Lower values allow more complex patterns but risk overfitting

# Activation functions
def sigmoid(x):
    """
    Sigmoid activation function: f(x) = 1 / (1 + e^(-x))
    Used in output layer for binary classification
    """
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    """Derivative of sigmoid function"""
    s = sigmoid(x)
    return s * (1 - s)

def relu(x):
    """
    ReLU activation function: f(x) = max(0, x)
    Used in hidden layers to introduce non-linearity
    """
    return np.maximum(0, x)

def relu_derivative(x):
    """Derivative of ReLU function"""
    return np.where(x > 0, 1, 0)

class NeuralNetwork:
    def __init__(self, layer_sizes):
        """
        Initialize neural network with given architecture
        Args:
            layer_sizes: List of integers, where:
                        - First element is the input size
                        - Last element is the output size (1 for binary classification)
                        - Middle elements are hidden layer sizes
        Example: [2, 3, 1] creates a network with:
                - 2 input neurons
                - 3 neurons in hidden layer
                - 1 output neuron
        """
        self.layer_sizes = layer_sizes
        self.parameters = {}
        
        # Initialize weights and biases with random values
        for i in range(1, len(layer_sizes)):
            # He initialization for weights
            self.parameters[f'W{i}'] = np.random.randn(layer_sizes[i], layer_sizes[i-1]) * np.sqrt(2/layer_sizes[i-1])
            self.parameters[f'b{i}'] = np.zeros((layer_sizes[i], 1))

    def forward_propagation(self, X):
        """
        Forward propagation step
        Args:
            X: Input data of shape (n_features, m_samples)
        Returns:
            Dictionary containing all activations
        """
        activations = {'A0': X}
        for i in range(1, len(self.layer_sizes)):
            Z = np.dot(self.parameters[f'W{i}'], activations[f'A{i-1}']) + self.parameters[f'b{i}']
            # Sigmoid for output layer, ReLU for hidden layers
            activations[f'A{i}'] = sigmoid(Z) if i == len(self.layer_sizes) - 1 else relu(Z)
        return activations
    
    def backward_propagation(self, X, Y, activations):
        """
        Backward propagation step
        Args:
            X: Input data
            Y: True labels
            activations: Activations from forward propagation
        Returns:
            Dictionary containing gradients
        """
        m = X.shape[1]
        gradients = {}
        
        # Calculate initial gradient for output layer
        dA = -(np.divide(Y, activations[f'A{len(self.layer_sizes)-1}']) - 
               np.divide(1 - Y, 1 - activations[f'A{len(self.layer_sizes)-1}']))
    
        # Propagate error backwards through the network
        for i in reversed(range(1, len(self.layer_sizes))):
            # Use appropriate derivative based on layer type
            if i == len(self.layer_sizes) - 1:
                dZ = dA * sigmoid_derivative(activations[f'A{i}'])
            else:
                dZ = dA * relu_derivative(activations[f'A{i}'])
            
            # Calculate gradients for weights and biases
            gradients[f'dW{i}'] = 1/m * np.dot(dZ, activations[f'A{i-1}'].T)
            gradients[f'db{i}'] = 1/m * np.sum(dZ, axis=1, keepdims=True)
            
            # Calculate gradient for next layer
            if i > 1:
                dA = np.dot(self.parameters[f'W{i}'].T, dZ)
    
        return gradients
    
    def update_parameters(self, gradients, learning_rate):
        """Update network parameters using gradients"""
        for i in range(1, len(self.layer_sizes)):
            self.parameters[f'W{i}'] -= learning_rate * gradients[f'dW{i}']
            self.parameters[f'b{i}'] -= learning_rate * gradients[f'db{i}']
            
    def compute_cost(self, AL, Y):
        """
        Compute binary cross-entropy cost
        Args:
            AL: Output of the network
            Y: True labels
        """
        m = Y.shape[1]
        cost = -1/m * np.sum(Y * np.log(AL + EPSILON) + (1-Y) * np.log(1 - AL + EPSILON))
        return np.squeeze(cost)
        
    def train(self, X, Y, num_iterations=ITERATIONS, learning_rate=LEARNING_RATE):
        """
        Train the neural network
        Args:
            X: Training data (n_features, m_samples)
            Y: Labels (1, m_samples)
            num_iterations: Number of training iterations
            learning_rate: Learning rate for gradient descent
        """
        costs = []
        for i in range(num_iterations):
            # Forward propagation
            activations = self.forward_propagation(X)
            # Backward propagation
            gradients = self.backward_propagation(X, Y, activations)
            # Update parameters
            self.update_parameters(gradients, learning_rate)

            # Record cost
            if i % PRINT_COST_EVERY == 0:
                cost = self.compute_cost(activations[f'A{len(self.layer_sizes)-1}'], Y)
                costs.append(cost)
                print(f"Cost after {i} iterations: {cost}")

        # Plot learning curve
        plt.figure(figsize=(8, 6))
        plt.plot(costs)
        plt.xlabel("Iterations (per hundreds)")
        plt.ylabel("Cost")
        plt.title("Learning curve")
        plt.show()

        return costs
    
    def predictions(self, X):
        """Generate binary predictions"""
        activations = self.forward_propagation(X)
        return activations[f'A{len(self.layer_sizes)-1}'] > 0.5
    
    def plot_decision_boundary(self, X, Y):
        """
        Plot the decision boundary
        Args:
            X: Input features (2, m_samples)
            Y: Labels (1, m_samples)
        """
        plt.figure(figsize=(10, 8))
        
        # Create a mesh grid
        h = 0.01  # Step size in the mesh
        x_min, x_max = X[0, :].min() - 0.5, X[0, :].max() + 0.5
        y_min, y_max = X[1, :].min() - 0.5, X[1, :].max() + 0.5
        xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
                            np.arange(y_min, y_max, h))
        
        # Flatten and combine the mesh points
        mesh_points = np.c_[xx.ravel(), yy.ravel()].T
        
        # Make predictions on the mesh points
        Z = self.predictions(mesh_points)
        Z = Z.reshape(xx.shape)
        
        # Plot the contour and training points
        plt.contourf(xx, yy, Z, cmap=plt.cm.RdYlBu, alpha=0.6)
        plt.scatter(X[0, Y[0, :] == 0], X[1, Y[0, :] == 0], c='red', label='Class 0', edgecolors='white')
        plt.scatter(X[0, Y[0, :] == 1], X[1, Y[0, :] == 1], c='blue', label='Class 1', edgecolors='white')
        
        plt.xlim(xx.min(), xx.max())
        plt.ylim(yy.min(), yy.max())
        plt.xlabel("Feature 1")
        plt.ylabel("Feature 2")
        plt.title("Decision Boundary")
        plt.legend()
        plt.show()

if __name__ == "__main__":
    # Dataset configuration
    RANDOM_SEED = 0       # Fixed seed for reproducible results
    N_SAMPLES = 2000      # Number of training points
                         # More samples generally improve generalization
                         # but increase training time
    NOISE_LEVEL = 0.02    # Probability of flipping a label
                         # Adds robustness to the model
                         # Higher values make learning more difficult
    
    # Triangle vertices (forming an equilateral triangle)
    TRIANGLE_SIZE = 0.5   # Scale of the triangle in the coordinate space
                         # Larger values make the triangle bigger relative to the space
                         # Smaller values make the classification task more challenging
    v1 = np.array([-TRIANGLE_SIZE, -TRIANGLE_SIZE/2])    # Bottom left
    v2 = np.array([TRIANGLE_SIZE, -TRIANGLE_SIZE/2])     # Bottom right
    v3 = np.array([0, TRIANGLE_SIZE])                    # Top center
    
    # Set random seed for reproducibility
    np.random.seed(RANDOM_SEED)
    
    # Modify the data generation to have more points near the boundary
    def generate_focused_points(n_samples, boundary_ratio=0.3):
        """
        Generate points with higher density near the triangle boundary
        
        Args:
            n_samples: Total number of points to generate
            boundary_ratio: Proportion of points to concentrate near boundary
                           Higher values focus more points near the decision boundary
                           which can help the model learn the boundary more precisely
        
        Returns:
            2D array of points with shape (2, n_samples)
        """
        # Generate uniform random points across the space
        uniform_points = np.random.uniform(-1, 1, (2, int(n_samples * (1-boundary_ratio))))
        
        # Generate points concentrated around the triangle perimeter
        boundary_points = np.zeros((2, int(n_samples * boundary_ratio)))
        for i in range(boundary_points.shape[1]):
            # Randomly select one of the three triangle edges
            t = np.random.random() * 3
            if t < 1:
                point = v1 + (v2 - v1) * t  # Bottom edge
            elif t < 2:
                point = v2 + (v3 - v2) * (t-1)  # Right edge
            else:
                point = v3 + (v1 - v3) * (t-2)  # Left edge
            
            # Add Gaussian noise to spread points around the boundary
            offset = np.random.normal(0, 0.1, 2)
            boundary_points[:, i] = point + offset
        
        # Combine uniform and boundary-focused points
        return np.hstack([uniform_points, boundary_points])
    
    # Generate points using the new function
    X = generate_focused_points(N_SAMPLES)
    
    # Function to check if a point is inside the triangle using barycentric coordinates
    def point_in_triangle(point):
        def sign(p1, p2, p3):
            return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1])
        
        d1 = sign(point, v1, v2)
        d2 = sign(point, v2, v3)
        d3 = sign(point, v3, v1)
        
        has_neg = (d1 < 0) or (d2 < 0) or (d3 < 0)
        has_pos = (d1 > 0) or (d2 > 0) or (d3 > 0)
        
        return not (has_neg and has_pos)
    
    # Create labels: 1 if inside triangle, 0 if outside
    Y = np.zeros((1, N_SAMPLES))
    for i in range(N_SAMPLES):
        point = np.array([X[0, i], X[1, i]])
        Y[0, i] = 1 if point_in_triangle(point) else 0
    
    # Add some noise by flipping labels randomly
    noise_mask = np.random.random(N_SAMPLES) < NOISE_LEVEL
    Y[0, noise_mask] = 1 - Y[0, noise_mask]
    
    # Create and train network (single pass)
    nn = NeuralNetwork([2, NUM_HIDDEN_LAYERS, NUM_HIDDEN_LAYERS//2, NUM_HIDDEN_LAYERS//4, 1])
    nn.train(X, Y, ITERATIONS, LEARNING_RATE)
    
    # Visualize decision boundary
    nn.plot_decision_boundary(X, Y)
    
    # Plot the triangle vertices for reference
    plt.figure(figsize=(10, 8))
    triangle = np.array([v1, v2, v3, v1])  # Close the triangle by repeating first vertex
    plt.plot(triangle[:, 0], triangle[:, 1], 'g--', label='Triangle boundary')
    plt.scatter(X[0, Y[0, :] == 0], X[1, Y[0, :] == 0], c='red', label='Class 0', alpha=0.6)
    plt.scatter(X[0, Y[0, :] == 1], X[1, Y[0, :] == 1], c='blue', label='Class 1', alpha=0.6)
    plt.xlim(-1, 1)
    plt.ylim(-1, 1)
    plt.xlabel("Feature 1")
    plt.ylabel("Feature 2")
    plt.title("Training Data with Triangle Boundary")
    plt.legend()
    plt.grid(True)
    plt.show()
