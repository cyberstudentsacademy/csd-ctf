# Pokemon PW Crack

- Published: 01/14/2024 (#1/5 in round)
- Category: Misc
- Points: 25
- Author: Vipin

Briefing: We have found the hash of our target, but cannot decrypt it can you? We know that his password is his favorite
pokemon + a random 2 digit number Ex. pokemon69. Can send us the password?

Hash: `76312B45FAAC2AF17B66176A4C440BBA`

## Write-up

<details>
<summary>Reveal write-up</summary>

First you need to determine the hash, using a tool like haiti will tell you it's NLTM. Next, you need to use a Tool like
CeWL to create a pokemon wordlist and write a python script to add a number between 10-99 to each Pokemon.

The command to run is hashcat -m 1000 [hashes.txt] [wordlist.txt]

Flag: csd{hitmonchan34}

</details>

Write-up by Vipin
