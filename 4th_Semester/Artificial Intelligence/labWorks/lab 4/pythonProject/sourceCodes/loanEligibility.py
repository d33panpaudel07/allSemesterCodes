def loan(details):
    if 18 < details['age'] < 65 and details['income'] == 'Y' and details['credit_score'] > 700 and details[
        'record'] == 'N' and details['loan'] == 'N':
        return "You are eligible for loan"

    return "You are ineligible for loan"


def main():
    details = {'age': int(input("Enter your age: ")), 'income': input("Is your income stable? Y/N : "),
               'credit_score': int(input("Enter your credit score: ")), 'record': input("Any past criminal records? Y/N : "),
               'loan': input("Any default loan? Y/N : ")}

    print(loan(details))


main()
