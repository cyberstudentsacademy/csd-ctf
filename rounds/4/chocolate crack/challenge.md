# chocolate crack

- Published: 04/06/2024 (#3/14 in round)
- Category: PWD Cracking
- Points: 25
- Author: Vipin

i love chocolate crack dont u? Wrap the password in csd{}.

TIP: Popular wordlists may not work.

## Attachments

- `$1$CSDCTF$9VCUkEcQqzqz/sg1aYAbM.`

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

Check out [Seclists](https://github.com/danielmiessler/SecLists), there has to be a wordlist in there that will help. Also the hash is in md5crypt.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

Download this wordlist: [10-million-password-list-top-1000000.txt](https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/10-million-password-list-top-1000000.txt) with your favorite hash cracking tool.

hashcat example:

```bash
hashcat -m 500 -a 0 '$1$CSDCTF$9VCUkEcQqzqz/sg1aYAbM.' 10-million-password-list-top-1000000.txt
```

Flag: ```csd{zaq8xsw5cde3}```

</details>

Write-up by kolmus
