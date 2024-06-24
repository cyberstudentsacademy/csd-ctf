# filler chall 1

- Published: 02/26/2024 (#11/11 in round)
- Category: Misc
- Points: 20
- Author: Vipin

since tmrw chall will be a lil late, had to pull out the emergency chall

Tip: look around the server (around jan)

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

look at my message _[refers to `qvipin`'s messages on Discord in CyberStudents]_ specifically, maybe with a flag?

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

Discord has a search functionality that allows us to search for messages with specific filters. The
`after:2023-12-31 before:2024-02-01` filter allows us to search for messages sent only in January 2024. (The challenge
and CTF was made in 2024, so we can infer that). Additionally, since we know the flag starts with `csd{`, we can add
that to our query.

Our final search query is `after:2023-12-31 before:2024-02-01 csd{`.
[One message](https://discord.com/channels/916144903686336513/916144904172896298/1196489406555623696) sparks our
interest, that includes a flag sent by the challenge author.

Flag: `csd{5t0pl00klng@tm@hme$$ag3s}`

</details>

Write-up by GodderE2D
