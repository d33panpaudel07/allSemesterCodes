def operation():
    while True:
        operation = input(
            "What do you want to perform, Encryption / Decryption? (E/D) : "
        ).upper()
        if operation == "E":
            return True
        elif operation == "D":
            return False
        else:
            print(
                "Invalid operation. Please enter 'E' for Encryption or 'D' for Decryption."
            )


def caesar_cipher(plain_text, key, choice):
    result = ""
    for char in plain_text:
        if char.isalpha():
            x = ord(char) - 65
            if choice == True:
                x = (x + key) % 26
            else:
                x = (x - key) % 26
            result += chr(x + 65)
        else:
            result += char

    return result


def main():
    plain_text = input("Enter text: ").upper()
    key = int(input("Enter key: "))
    choice = operation()
    if choice == True:
        print("Encrypted text: ", caesar_cipher(plain_text, key, choice))
    else:
        print("Decrypted text: ", caesar_cipher(plain_text, key, choice))

main()
