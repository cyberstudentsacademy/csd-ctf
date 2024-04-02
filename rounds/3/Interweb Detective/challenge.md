# Interweb Detective

- Published: 03/11/2024 (#2/6 in round)
- Category: OSINT
- Points: 75
- Author: GodderE2D

Are you able to find DespairBlanket91's email address? We know that they are a *beginner programmer* and loves *watching videos*.

Tip: Perhaps, a tool can help you with the search. The flag is in csd{email} format.

## Attachments

- N/A

## Hint

This hint costed 15 points.

<details>
<summary>Reveal hint</summary>

An open-source tool to search for social media accounts based on a username is [Sherlock](https://github.com/sherlock-project/sherlock).

If you've got the first part, try deducting what the italicized words mean in the challenge description.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

- Using a tool like sherlock
  - ```python3 sherlock Hopequilt19```
  - Ignore false-positives, then you get a Scratch account: https://scratch.mit.edu/users/DespairBlanket91
    - *Beginner programmer* (from description) is also a hint
  - Scratch user's bio mentions another name, Hopequilt19
- Deduct 2nd italicized phrase from description
  - A popular platform to watch videos is Youtube
  - Go to https://youtube.com/@Hopequilt19
  - Sign in, click on "More about this channel", get email

Flag: ```csd{csd.5Cr47CH1N6V1D305@example.com}```


</details>

Write-up by [GodderE2D](https://godder.xyz)