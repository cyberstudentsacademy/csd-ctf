# vipenc 2

- Published: 05/08/2024 (#3/7 in round)
- Category: Cryptography
- Points: 75
- Author: Vipin

ap world in a week yall, im legit dying here... (Unrelated to challenge)

## Attachments

- [chall.zip](chall.zip)

## Hint

This hint costed 5 points.

<details>
<summary>Reveal hint</summary>

Observe the encoding process for each string. Begin by examining the code from the bottom of `encode.py` as it mirrors the sequence of operations required for decoding.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

Upon downloading the challenge, we are provided with 2 files in the ZIP. A enc file (Meaning the encrypted text/flag) and `encode.py`. After taking a look at `encode.py` this function stands out to me the most.

```python
def xor_and_base64_encode(input_bytes):
    xored_bytes = bytes([byte ^ 4 for byte in input_bytes])
    base64_encoded = base64.b64encode(xored_bytes)
    hex_encoded = base64_encoded.hex()
    return hex_encoded
```

Here is what it is doing:
1. Takes the input provided by the user and XOR's it by 4.
2. Base64 encodes the XOR'ed bytes.
3. Hex encode the bytes that were just encoded in Base64.

Seems simple enough to solve, let's make a solve script (or ask ChatGPT but thats boring)!

```python
import base64

file = open("enc", "r");enc = file.read() # opening/reading the enc file

unhexed = bytes.fromhex(enc) # decrypting from hex
unbase64ed = base64.b64decode(unhexed) # decrypting from base64
final = bytes([byte ^ 4 for byte in unbase64ed]) # Xoring by 4

print(final)
```

Let's run it!

```bash
❯ python3 sol.py
b'csd{4P_W0r1D_3X4M_1N_4_W33K_P1Z_Pr4Y_F0r_M3}'
```

Flag: ```csd{4P_W0r1D_3X4M_1N_4_W33K_P1Z_Pr4Y_F0r_M3}```


</details>

Write-up by [Vipin](https://vipin.xyz)