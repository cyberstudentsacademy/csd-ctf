# Webhunt

- Published: 01/17/2024 (#5/5 in round)
- Category: Web/RE
- Points: 100
- Author: Vipin

Briefing: Agent, they took our best man vip3r hostage and gave us a challenge. They will free him if we find the flag in
their website. Good luck.

Credits to kshau for fixing some stuff

## Attachments

- https://437095c8-c22d-4b63-bf98-9b34cbcdc2dd-00-1r8uurngzj33.picard.replit.dev/
- [webhunt.py](webhunt.py) (note: this file was not part of the original challenge description, but was added for the
  archive)

## Write-up

<details>
<summary>Reveal write-up</summary>

This one is the hardest challenge out of all the 5 in the round to most people so lets split it up into 3 parts for each
part of the flag.

Part 1: Looking at the site visually finds the first part of the flag in icon1.png

Part 2: Looking through the source of the webpage is the next step of any web challenge and after looking in
customscripts.js leads us to the 2nd part of the flag

Part 3: When looking around the source you will find a link which is supposed to redirect to WebThemez.com but instead
redirect to http://tinyurl.com/Ilooksuspiciousclickme and when clicked gives us a python script called "webhunt.py" that
we have to reverse engineer. Looking at the python code there is 2 ways of going about this either decoding the ascii
text in the output code or finding the correct number or else the python code will delete itself. And if we were to look
at this line specifically "''.join([chr(i) for i in [int((50 + 58) / 2), int(((50 + 62) / 2) + 1), int((50 + 46) / 2),
int((62 + 38) / 2), int((56 + 48) / 2)]]):" all we have to do is solve them using a calculator or ask chatgpt and once
decoded gives us 69024 which when we enter gives us this base 64 string
"Vmtkb2JFbEVUbmxhUTBKM1dWaEtNRWxIT1cxSlNGSnZXbE5DYldKSFJtNUpSMng2U1VOS2FGa3lhSEJZTWpsNllWYzFNRmd5VG05WlYzaHpabE5KUFE="
which when decoded over and over again from base64 gives us the third part of the flag

Flag: csd{ping_me_in_general_if_you_want_nodachi_osint_chall}

</details>

Write-up by Vipin
