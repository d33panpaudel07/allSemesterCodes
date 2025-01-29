def check_loan_eligibility(age, stable_income, credit_score, criminal_record, loan_default):
    if age < 18 or age > 65:
        return "Not eligible for a loan due to age."
    if stable_income == "no":
        return "Not eligible for a loan due to unstable income."
    if credit_score > 700:
        return "Eligible for a loan based on credit score."
    if criminal_record == "yes":
        return "Not eligible for a loan due to criminal record."
    if loan_default == "yes":
        return "Not eligible for a loan due to previous loan default."
    if 18 <= age <= 65 and stable_income == "yes":
        return "Eligible for a loan based on age and stable income."

    return "Not eligible for a loan based on the given criteria."

def main():
    try:
        age = int(input("Enter your age: "))
        stable_income = input("Do you have a stable income? (yes/no): ").strip().lower()
        credit_score = int(input("Enter your credit score: "))
        criminal_record = input("Do you have a criminal record? (yes/no): ").strip().lower()
        loan_default = input("Have you defaulted on a loan before? (yes/no): ").strip().lower()

        # Validate inputs
        if stable_income not in ['yes', 'no']:
            print("Error: Stable income must be 'yes' or 'no'.")
            return
        if criminal_record not in ['yes', 'no']:
            print("Error: Criminal record must be 'yes' or 'no'.")
            return
        if loan_default not in ['yes', 'no']:
            print("Error: Loan default must be 'yes' or 'no'.")
            return

        # Check eligibility
        eligibility = check_loan_eligibility(age, stable_income, credit_score, criminal_record, loan_default)
        print(eligibility)
    except ValueError:
        print("Error: Invalid input. Please enter numbers where required.")

main()
