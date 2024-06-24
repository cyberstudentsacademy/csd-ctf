# Brute For Loot

- Published: 02/09/2024 (#6/11 in round)
- Category: Misc
- Points: 90
- Author: Kshau

Try cracking the password! (command to crack the zip "login.exe \<password>")

## Attachments

- [BruteForLoot.zip](BruteForLoot.zip)

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

Make a python script that tries a password from rockyou

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

Since we know that it's a password, it can be a common one where a
[dictionary attack](https://en.wikipedia.org/wiki/Dictionary_attack) can be used to crack it. Based off the previous
challenge, `rockyou.txt` was used as the wordlist. We can write a script to iterate through the wordlist and determine
the password.

<!-- TODO: Include actual script -->

After writing the script, we now know the password, which is `nicole1`.

Flag: `csd{GmoWiViKVkfZnLvO3moQnAB96lp}`

</details>

Write-up by GodderE2D
