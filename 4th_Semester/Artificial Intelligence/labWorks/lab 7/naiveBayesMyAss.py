from sklearn.preprocessing import LabelEncoder
from sklearn.naive_bayes import GaussianNB
import numpy as np

# Data
weather = ['Sunny', 'Sunny', 'Overcast', 'Rainy', 'Rainy', 'Rainy', 'Rainy', 'Overcast', 'Sunny', 'Sunny', 'Rainy',
           'Sunny', 'Overcast', 'Rainy']
temp = ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Cool', 'Mild', 'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Mild']
humidity = ['High', 'High', 'High', 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'Normal', 'Normal', 'High',
            'Normal', 'High']
wind = ['Weak', 'Weak', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong',
        'Weak', 'Weak']
play = ['No', 'No', 'Yes', 'Yes', 'Yes', 'No', 'Yes', 'No', 'Yes', 'Yes', 'Yes', 'Yes', 'Yes', 'No']

# Encode categorical data into numeric values
encoder = LabelEncoder()
weather_encoded = encoder.fit_transform(weather)
temp_encoded = encoder.fit_transform(temp)
humidity_encoded = encoder.fit_transform(humidity)
wind_encoded = encoder.fit_transform(wind)
play_encoded = encoder.fit_transform(play)

# Combine features into a single dataset
features = np.column_stack((weather_encoded, temp_encoded, humidity_encoded, wind_encoded))
print("Input data (features):")
print(features)
print("Output data (play):")
print(play_encoded)

# Train the Gaussian Naive Bayes model
model = GaussianNB()
model.fit(features, play_encoded)

# Test the model with a new input
# Example input: Sunny (0), Hot (0), High Humidity (0), Weak Wind (0)
test_input = np.array([[0, 0, 0, 0]])
predicted = model.predict(test_input)

# Decode the prediction back to 'Yes' or 'No'
predicted_label = encoder.inverse_transform(predicted)[0]
print("Predicted value:", predicted_label)

if predicted_label == 'Yes':
    print("Play Tennis: Yes")
else:
    print("Play Tennis: No")
