# vipenc

- Published: 04/09/2024 (#5/14 in round)
- Category: Cryptography
- Points: 110
- Author: Vipin

official csd encryption method, on monday's, at 8 pm if u want to send anything u need to encrypt it in this (joke)

## Attachments

- [VIPenc.zip](VIPenc.zip)

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

This is a tricky challenge! There are 2 ways of going about this. Understanding how the cipher works and solving it manually, or making a python script that is the complete opposite of the encryption script

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

You need to figure out how to decrypt the flag by reversing the operations of the `encoder.py`

example solve script:

```py
def reverse_shift_decrypt(ciphertext):
    decrypted_text = ''
    for i, char in enumerate(ciphertext):
        shift_amount = i
        shifted_char = chr((ord(char) - ord('a') - shift_amount) % 26 + ord('a')) if char.islower() else \
            chr((ord(char) - ord('A') - shift_amount) % 26 + ord('A')) if char.isupper() else char
        decrypted_text += shifted_char
    return decrypted_text[::-1]

if __name__ == "__main__":
    ciphertext = "}O0174I1VDWX0P_U0_5G43I_141D1IJ0_4_51S7_3Z4D_WH4_5L0174Q_I371WE_3U7_07_D147_B1U0J5_1_38H4X_3B1C_V3E11_S_38A4Q_5y3QZ1O_3K01_1{yoz"
    decrypted_text = reverse_shift_decrypt(ciphertext)
    print("Decrypted text:", decrypted_text)
```

Flag: `csd{1_10V3_C1PH3r5_M4Y83_U_11K3D_M1N3_M4Y83_1_5H0U1D_741K_70_7H3_UN173D_N4710N5_4ND_M4K3_7H15_4_0FF1C141_M34N5_0F_C0MMUN1C4710N}`
</details>

Write-up by [Vipin](https://vipinb.xyz)
