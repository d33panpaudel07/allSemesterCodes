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


def vigenere_cipher(plain_text, key, choice):
    result = ""
    key_index = 0
    for char in plain_text:
        key_index = key_index % len(key)
        if char.isalpha():
            if choice:
                x = (ord(char) - 65 + ord(key[key_index]) - 65) % 26
            else:
                x = (ord(char) - 65 - ord(key[key_index]) - 65) % 26
            result += chr(x + 65)
            key_index = key_index + 1
        else:
            result += char
    return result


def main():
    plain_text = input("Enter text: ").upper()
    key = input("Enter key: ").upper()
    choice = operation()
    if choice == True:
        print("Encrypted text: ", vigenere_cipher(plain_text, key, choice))
    else:
        print("Decrypted text:", vigenere_cipher(plain_text, key, choice))


main()
