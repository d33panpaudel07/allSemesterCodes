from sklearn import preprocessing

# Initialize LabelEncoder
le = preprocessing.LabelEncoder()

# Correct input lists
weather = ['Sunny','Sunny','Overcast','Rainy','Rainy','Rainy','Rainy','Overcast']
temp = ['Hot','Hot','Hot','Mild','Cool','Cool','Cool','Mild']
humidity = ['High','High','High','High','Normal','Normal','Normal','High']
wind = ['Weak','Strong','Weak','Average','Strong','Average','Weak','Weak']
play = ['No','No','Yes','Yes','Yes','No','Yes','No']

# Encode the categorical features using LabelEncoder
weather_number = le.fit_transform(weather)
temp_number = le.fit_transform(temp)
humidity_number = le.fit_transform(humidity)
wind_number = le.fit_transform(wind)
play_number = le.fit_transform(play)

# Output the encoded results
print("Weather: ", weather_number)
print("Temperature: ", temp_number)
print("Humidity: ", humidity_number)
print("Wind: ", wind_number)
print("Play: ", play_number)

features = list(zip(weather_number, temp_number, humidity_number, wind_number))


# fit_transform(list) => converts given values to numbers
# 
