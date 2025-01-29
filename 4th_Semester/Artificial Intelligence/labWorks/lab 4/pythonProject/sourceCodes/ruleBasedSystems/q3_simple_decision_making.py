def convert_to_24_hour(time_str):
    time_str = time_str.strip().upper()
    if "AM" in time_str or "PM" in time_str:
        time, period = time_str.split()
        time = int(time)
        if period == "PM" and time != 12:
            time += 12
        if period == "AM" and time == 12:
            time = 0
    else:
        time = int(time_str)
    return time

def simple_decision_making(time, is_weekday, is_sunny):
    rules = {
        (lambda t, w: 6 <= t < 8 and w == "yes", None): "Time to go to work.",
        (lambda t, w: 12 <= t <= 13, None): "Time for lunch.",
        (lambda t, w: 21 <= t <= 22, None): "Time to go to bed.",
        (lambda t, w, s: w == "no" and s == "yes"): "Go for a walk."
    }

    for (time_condition, sunny_condition), result in rules.items():
        if (time_condition is None or time_condition(time, is_weekday)) and \
           (sunny_condition is None or sunny_condition(time, is_weekday, is_sunny)):
            return result

    return "No specific action for this time."

def main():
    try:
        time_str = input("Enter the current time:")
        time = convert_to_24_hour(time_str)
        if time < 0 or time > 23:
            raise ValueError("Time must be between 0 and 23.")
        is_weekday = input("Is it a weekday? (yes/no): ")
        is_sunny = input("Is the weather sunny? (yes/no): ")
        if is_weekday not in ['yes', 'no'] or is_sunny not in ['yes', 'no']:
            raise ValueError("Input for 'is_weekday' and 'is_sunny' must be 'yes' or 'no'.")
        decision = simple_decision_making(time, is_weekday, is_sunny)
        print(decision)
    except ValueError as e:
        print(f"Error: {e}")

main()
