def weather_forecast(sky, temperature, wind):
    rules = {
        ("cloudy", None, "none"): "It might rain.",
        ("clear", lambda temp: temp < 0, None): "It might snow.",
        (None, lambda temp: temp > 30, "none"): "It might be a hot day.",
        ("clear", None, "windy"): "It might be a pleasant day."
    }

    for (sky_condition, temp_condition, wind_condition), forecast in rules.items():
        if (sky_condition is None or sky == sky_condition) and \
           (temp_condition is None or temp_condition(temperature)) and \
           (wind_condition is None or wind == wind_condition):
            return forecast

    return "Weather conditions unclear, please check the forecast later."

def main():
    sky = input("Enter the sky condition (cloudy/clear): ")
    temperature = float(input("Enter the temperature in °C: "))
    wind = input("Enter the wind condition (none/windy): ")
    forecast = weather_forecast(sky, temperature, wind)
    print(forecast)

main()
