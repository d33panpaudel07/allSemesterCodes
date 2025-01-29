class InvalidInput(Exception):
    pass


class NoInput(InvalidInput):
    pass


class MaxInput(NoInput):
    pass


def takingInput(input):
    reply = ", Your input: " + str(input)
    if len(input) > 10:
        raise MaxInput(reply)
    elif input == "":
        raise NoInput(reply)
    elif not input.isalnum():
        raise InvalidInput(reply)
    else:
        print("Processing input:" + input)


def main():
    inputs = ["", "9876543210.", "helloworld", "ram", "shyam", "gita", "99999999999", "", "*/"]

    for inp in inputs:
        try:
            takingInput(inp)
        except MaxInput as e:
            print(f"Max number of input{e}")
        except NoInput as e:
            print(f"No input given{e}")
        except InvalidInput as e:
            print(f"Invalid input{e}")

    # for custom_class in [InvalidInput, NoInput, MaxInput]:
    #     try:
    #         raise custom_class()
    #     except MaxInput:
    #         print("Max number of Input characters.")
    #     except NoInput:
    #         print("No input given.")
    #     except InvalidInput:
    #         print("Invalid input given.")


main()
