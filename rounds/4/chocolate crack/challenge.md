# chocolate crack

- Published: 04/05/2024 (#3/14 in round)
- Category: PWD Cracking
- Points: 50
- Author: Kshau

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

As the tip says, popular wordlists don't work. With this knowledge we can assume that *rockyou.txt* wouldn't work. A popular place to look for password wordlists is [Seclists](https://github.com/danielmiessler/SecLists), the biggest wordlist in the repository is *xato-net-10-million-passwords.txt*. Let's try to crack with that!

```bash
echo '$1$CSDCTF$9VCUkEcQqzqz/sg1aYAbM.' > hash && hashcat -m 500 hash /Users/vipin/tech/CTFs/wordlists/xato-net-10-million-passwords.txt
```

And from that we get the password `$1$CSDCTF$9VCUkEcQqzqz/sg1aYAbM.:zaq8xsw5cde3`. After wrapping with csd{}, you get the flag.


Flag: ```csd{zaq8xsw5cde3}```

</details>

Write-up by [Vipin](https://vipinb.xyz)

