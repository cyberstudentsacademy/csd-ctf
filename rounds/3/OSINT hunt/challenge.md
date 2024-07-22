# OSINT hunt

- Published: 03/17/2024 (#3/6 in round)
- Category: OSINT/Misc.
- Points: 50
- Author: Vipin

Dadgummit, they sent us on another darn tootin' scavenger hunt.

## Attachments

- [user-profile-icon.svg.zip](user-profile-icon.svg.zip)

## Hint

This hint costed 15 points.

<details>
<summary>Reveal hint</summary>

inside svg -> how to view gmail name -> answer cve question -> unlock zip -> flagy flag

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

Upon opening the *.svg*, we see a hexadecimal string that decodes to **whoamicsd@gmail.com**

Using a tool like [epieos.com](https://epieos.com/), we can take a look at the Gmail name and other information. 

> Gmail Name: vipinb.xyzslashconfig yuh

Heading to [vipinb.xyz/config](https://vipin.xyz/config), we see 2 things. 1: a Base58 encoded string 2: a link to a zip which is password protected. Decoding the Base58 string asks...

>What is the CVE identifier for the security vulnerability that compromises Minecraft's in-game chat, allowing unauthorized access to personal data by server owners and malicious players?

And the answer to that is...

> CVE-2021-44228

From here we can unlock the password protected zip with the answer to the question and inside is the flag.


Flag: ```csd{simpleflagyflagcusilikeflags}```

</details>

Write-up by [Vipin](https://vipin.xyz)