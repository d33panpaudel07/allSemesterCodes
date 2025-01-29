def smart_home_action(temperature, is_dark, at_home, security_armed, door_open):
    actions = []
    rules = {
        (lambda temp: temp < 18, None, None, None, None): "Turn on the heater.",
        (lambda temp: temp > 25, None, None, None, None): "Turn on the air conditioner.",
        (None, lambda dark, home: dark == "yes" and home == "yes", None, None, None): "Turn on the lights.",
        (None, None, None, lambda armed, door: armed == "yes" and door == "yes", None): "Sound the alarm."
    }

    for (temp_cond, light_cond, home_cond, sec_cond, door_cond), action in rules.items():
        if (temp_cond is None or temp_cond(temperature)) and \
                (light_cond is None or light_cond(is_dark, at_home)) and \
                (home_cond is None or home_cond(at_home)) and \
                (sec_cond is None or sec_cond(security_armed, door_open)) and \
                (door_cond is None or door_cond(door_open)):
            actions.append(action)

    if not actions:
        actions.append("No specific action required.")

    return actions


def main():
    try:
        temperature = float(input("Enter the current temperature in °C: "))
        is_dark = input("Is it dark outside? (yes/no): ")
        at_home = input("Is someone at home? (yes/no): ")
        security_armed = input("Is the security system armed? (yes/no): ")
        door_open = input("Is a door opened? (yes/no): ")
        if is_dark not in ['yes', 'no'] or at_home not in ['yes', 'no'] or \
                security_armed not in ['yes', 'no'] or door_open not in ['yes', 'no']:
            print("Error: All inputs must be 'yes' or 'no'.")
            return

        actions = smart_home_action(temperature, is_dark, at_home, security_armed, door_open)
        for action in actions:
            print(action)
    except ValueError as e:
        print(f"Error: {e}")
main()
