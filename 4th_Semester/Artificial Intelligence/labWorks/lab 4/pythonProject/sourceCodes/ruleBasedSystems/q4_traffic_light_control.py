def traffic_light_action(light_color, pedestrian_button):
    if light_color == "red":
        return "Cars must stop."
    elif light_color == "green":
        return "Cars can go."
    elif light_color == "yellow":
        return "Cars must slow down and prepare to stop."
    elif pedestrian_button == "yes":
        return "The light will turn red after a short delay."
    else:
        return "No specific action for the given light state."


def main():
    light_color = input("Enter the traffic light color (red, green, yellow): ").strip().lower()
    pedestrian_button = input("Is the pedestrian button pressed? (yes/no): ").strip().lower()

    if light_color not in ['red', 'green', 'yellow']:
        print("Error: Light color must be 'red', 'green', or 'yellow'.")
        return
    if pedestrian_button not in ['yes', 'no']:
        print("Error: Pedestrian button input must be 'yes' or 'no'.")
        return

    action = traffic_light_action(light_color, pedestrian_button)
    print(action)


main()
