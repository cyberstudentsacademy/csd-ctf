# MultiClicking

- Published: 02/10/2024 (#7/11 in round)
- Category: Web Exploitation
- Points: 100
- Author: kshau

How fast can you click? 10 cps? 14 cps? Prove it by click all the buttons at the same time!

Tested by Vipin

## Attachments

- https://a1316426-4d39-4df6-bcf5-3bc0ac1a0082-00-2um487so8vo3h.janeway.replit.dev/

## Hint

This hint costed 20 points.

<details>
<summary>Reveal hint</summary>

Make a cURL request that POST's "btn1, btn2, btn3".

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

When visiting the site, it appears that we need to click all three buttons at the same time to continue. When we inspect
the request in the Network tab of DevTools, we see that the payload only includes the button that was clicked inside the
array.

Therefore, we can use cURL to send a POST request with all three buttons included in the array.

```sh
curl -H 'Content-Type: application/json' \
  -d '{ "buttons": ["btn1", "btn2", "btn3"] }' \
  -X POST \
  https://a1316426-4d39-4df6-bcf5-3bc0ac1a0082-00-2um487so8vo3h.janeway.replit.dev/
```

After running the command, we see the flag in the response.

<!-- prettier-ignore-start -->
```json
{"status":"ok","message":"Those are the correct buttons!","flag":"csd{MY_3D175_4r3_7H3_8357_5HU7_UP_K5H4U}"}
```
<!-- prettier-ignore-end -->

Flag: `csd{MY_3D175_4r3_7H3_8357_5HU7_UP_K5H4U}`

</details>

Write-up by GodderE2D
