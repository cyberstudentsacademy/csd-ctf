# Nokia's secret

- Published: 01/14/2024 (#2/5 in round)
- Category: Forensics/Google
- Points: 10
- Author: Vipin

Description: find what is hiding in the image

## Attachments

- [stegedimage.png.zip](stegedimage.png.zip)

## Write-up

<details>
<summary>Reveal write-up</summary>

Using zsteg, we find a google drive link. Inside the google drive link there is a txt file which has text encrypted in
ATBASH. Once decrypted we need to find the CVE associated to get the flag.

Flag: csd{CVE-2023-37192}

</details>

Write-up by Vipin
