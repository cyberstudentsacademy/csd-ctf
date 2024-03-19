# Vig you!

- Published: 02/08/2024 (#5/11 in round)
- Category: Cryptography
- Points: 80
- Author: Vipin

My friend **Viggy** sent me a cipher. he told me that to decode it you need... and then he started yapping and then said
something about _"you rock"_ and _"keys"_ and gave me a piece of paper. Can you decode it for me?

## Attachments

- [cipher.txt.zip](cipher.txt.zip)

## Hint

This hint costed 35 points.

<details>
<summary>Reveal hint</summary>

Vignere _[sic]_ & Rockyou.txt, Password has something to do with Linux & Penguins?!

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

After downloading the file, it appears that the text is an encoded text or cipher of some sort. The title and challenge
description suggests that the specific cipher being used is the Vigenère cipher.

_You rock_ refers to the common password list `rockyou.txt`. The list is commonly used for
[dictionary attacks](https://en.wikipedia.org/wiki/Dictionary_attack), which we can use to decode this cipher.

We can write a script to decode the Vigenère cipher using the `rockyou.txt` wordlist. The script will iterate through
the wordlist and attempt to decode the cipher using each word as the key. Because we know that the flag starts with
`csd`, we can use this to filter the results. Additionally, the flag will likely be in 1337 code (leet speak).

<!-- TODO: Include actual script -->

Therefore, the key is `tuxtla`.

Flag: `csd{V16N3r3_5UCK5_N0_M0r3}`

</details>

Write-up by GodderE2D
