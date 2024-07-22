# Salty

- Published: 05/12/2024 (#4/7 in round)
- Category: PWD Cracking
- Points: 65
- Author: GodderE2D

We found a database file left behind, can you find **Viper**'s password from it?

Tip: Flag is in `csd{password}` format.

## Attachments

- [salty.sqlite](salty.sqlite)

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

Some tools allow you to crack a password with a wordlist, even with a salt. Don't waste your time by trying a big wordlist!

The two most common ways for salts to be concatenated are `<salt><hash>` and `<hash><salt>` (without the brackets).

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

Use a SQLite browser/viewer (any will work) to see the `Users` table. Inside, there should be a password and salt field for the user Viper.

We can then use `hashid` to identify that the hash is SHA256, and since we have a salt as well, we'll be using `hashcat` mode 1410. We can also use [a small wordlist from SecLists](<https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/10-million-password-list-top-1000.txt>).

```bash
hashcat -m 1410 -a 0 2073f3f9b6eba92482c8e349680f61326b2160c633e0c3e992ebffd7c4322d18:bypIaniDBrnh ./10-million-password-list-top-1000.txt
```

It should only take a few seconds before hashcat cracks the password with the hash we provide:

```plaintext
2073f3f9b6eba92482c8e349680f61326b2160c633e0c3e992ebffd7c4322d18:bypIaniDBrnh:beaver
```

Flag: `csd{beaver}`

</details>

Write-up by [GodderE2D](https://godder.xyz)