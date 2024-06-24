# Just Graduated

- Published: 04/10/2024 (#6/14 in round)
- Category: OSINT
- Points: 135
- Author: GodderE2D

Can you find this person's organization name that he is self-employed in?

Tips:

- Once you find the organization name, you'll be able to get it to csd{} format. You shouldn't have to wrap it in csd{} yourself.
- If you see the author's (GodderE2D) name anywhere, you're going the wrong way
- Only use passive forms of OSINT
- If you cannot access the attached site, please DM Modmail

## Attachments

- [https://twitter.com/VaughnWest48](https://twitter.com/VaughnWest48)

## Hint

This hint costed 15 points.

<details>
<summary>Reveal hint</summary>

- Some images may appear to be stock images, some may not actually be
- 3912

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

![1](1.png)

This photo is edited with text to show "modslides.com" as the recipient of the check
Visiting the site gives us nothing, DNS records or Google searches doesn't return any interesting results that doesn't mention the author
Searching the domain using [WHOIS](https://www.whois.com/whois/modslides.com) returns Y3Nke0YxcjNEXzBOXzdIM19GMXI1N19ENFl9 as an organization
Decoding from Base64 gives us the flag

Flag: `csd{F1r3D_0N_7H3_F1r57_D4Y}`

</details>

Write-up by [GodderE2D](https://godder.xyz)
