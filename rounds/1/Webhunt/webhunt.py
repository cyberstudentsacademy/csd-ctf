import base64
import os

attempts_left = 3

def get_original_string():
    part1 = ''.join([chr(i) for i in [86, 109, 116, 107, 98, 50, 74, 70, 98, 69, 86, 85, 98, 109, 120, 104, 85, 84, 66, 75, 77, 49, 100, 87, 97, 69]])
    part2 = ''.join([chr(i) for i in [116, 78, 82, 87, 120, 73, 84, 49, 99, 120, 83, 108, 78, 71, 83, 110, 90, 88, 98, 69, 53, 68, 89, 108]])
    part3 = ''.join([chr(i) for i in [100, 75, 83, 70, 74, 116, 78, 85, 112, 83, 77, 110, 103, 50, 85, 49, 86, 79, 83, 50, 70, 71, 97, 51, 108, 104]])
    part4 = ''.join([chr(i) for i in [83, 69, 74, 90, 84, 87, 112, 115, 78, 108, 108, 87, 89, 122, 70, 78, 82, 109, 100, 53, 86, 71, 48, 53, 87, 108]])
    part5 = ''.join([chr(i) for i in [89, 122, 97, 72, 112, 97, 98, 69, 53, 75, 85, 70, 69, 61]])

    return base64.b64decode(''.join([part1, part2, part3, part4, part5])).decode('latin-1')

def encrypt_string(correct_number):
    original_string = get_original_string()
    encoded_original = base64.b64encode(original_string.encode('latin-1')).decode('latin-1')
    encrypted_string = base64.b64encode(correct_number.encode('latin-1')).decode('latin-1')
    print("Encrypted String:", encrypted_string)
    print("Encoded Original String:", encoded_original)

if __name__ == "__main__":
    while attempts_left > 0:
        correct_number = input("Enter the correct number: ")

        if len(correct_number) > 0 and correct_number.isdigit() and correct_number == ''.join([chr(i) for i in [int((50 + 58) / 2), int(((50 + 62) / 2) + 1), int((50 + 46) / 2), int((62 + 38) / 2), int((56 + 48) / 2)]]):
            encrypt_string(correct_number)
            break
        else:
            attempts_left -= 1
            print(f"Incorrect number. {attempts_left} attempts left.")

    if attempts_left == 0:
        print("Maximum attempts reached. Deleting the code...")
        os.remove(__file__)