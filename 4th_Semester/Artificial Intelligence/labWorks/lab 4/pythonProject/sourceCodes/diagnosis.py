def diagnosis(symptoms):
    if "fever" in symptoms and "cough" in symptoms:
        return "You have flu."

    if "headache" in symptoms and "fever" in symptoms:
        return "You hava migraine."

    if "sore throat" in symptoms and "cough" in symptoms:
        return "You have a cold."

    if "runny nose" and "sneezing" in symptoms:
        return "You may have allergy"

    else:
        return "Please refer to a doctor, as the symptoms are unclear"


def main():
    symptoms = []

    print("Enter your symptoms: (Type 'done' if finished")
    while True:
        symptom = input("Symptom: ")

        if symptom == "done":
            break

        symptoms.append(symptom)

    print(diagnosis(symptoms))

main()