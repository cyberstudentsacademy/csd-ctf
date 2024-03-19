# Loggy log's

- Published: 01/16/2024 (#4/5 in round)
- Category: Misc/Logs
- Points: 35
- Author: Vipin

Description: Agent, we found the logs in the hacker's computer can you find anything unusual?

Tip: look around the log to find the flag

## Attachments

- [Windows.log.zip](Windows.log.zip)

## Write-up

<details>
<summary>Reveal write-up</summary>

Inside the file you need to look for anything unusual, and we see this "ZmFrZXtmbGFnfQ:69" but when decoded from base64
it is a fake flag. Eventually we find this string "Y3Nke3lvdV9mb3VuZF9tZTQ5MjR9" which decoded gives us the flag.

Flag: csd{you_found_me4924}

</details>

Write-up by Vipin
