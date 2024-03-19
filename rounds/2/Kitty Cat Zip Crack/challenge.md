# Kitty Cat Zip Crack

- Published: 02/04/2024 (#1/11 in round)
- Category: OSINT/PWD Crack
- Points: 125
- Author: Vipin

Agent, we finally infiltrated Mercantil industries secret plan, but it is stored in a Password locked zip file made by
the owner and the only social media he has is Tumblr. Also, we did see him type the password once but we don't remember
anything other than there being some numbers at the end. Can you crack the zip?

Tip: the password has no capital letters and it is made up of information in the tumblr

## Attachments

- [challenge.zip](challenge.zip)
- https://www.tumblr.com/blog/hermon-mcshooty

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

Need help making the wordlist, try using Python & CeWL. Already have the Wordlist, but don't know how to crack the ZIP,
check out my writeup for a similar challenge https://www.vipinb.xyz/blog/ctflearn1#my-friend-john.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

To solve this challenge we get his Tumblr and the password protected zip. Since all the information needed to crack the
password is on the Tumblr we can use CeWL to get all the words on the site and to mix the words up and put all the
number at the end we can make a script to create a wordlist for us to use and we can crack the zip using a tool like
fcrackzip to get the flag inside

Flag: csd{tUberClo$is_kitty_0n_tumbLr}

</details>

Write-up by Vipin
