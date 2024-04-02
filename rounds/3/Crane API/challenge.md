# Crane API

- Published: 03/19/2024 (#5/6 in round)
- Category: OSINT/Misc.
- Points: 100
- Author: GodderE2D

This developer tried to hide the API key from their GitHub repository, but they didn't do a very good job at covering all the bases.

Tip: The flag is the API key in `csd{api_key}` format.

## Attachments

- [https://github.com/deepskylight16/crane-api](https://github.com/deepskylight16/crane-api)

## Hint

This hint costed 20 points.

<details>
<summary>Reveal hint</summary>

By looking at [this commit](https://github.com/deepskylight16/crane-api/commit/cf129dff8631600fb467dc3351bc2e0eb1d6036d), you can see that the developer tried to remove their `.env` file from the commit history using `git filter-repo`.

This is the same method recommended by GitHub. Try reading their documentation on this [here](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/removing-sensitive-data-from-a-repository). In particular, focus on what is being said in the warning alert.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

- `cf129df` mentions that git filter-repo is used to remove the secret from the commit history
  - This is the same method used here: https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/removing-sensitive-data-from-a-repository
  - In the warning text in the doc, it says that even when removed using `git filter-repo`, existing forks will remain
  - So forks should be looked at to see if the secret is still there
- The removed text in `ef00fbd` tells us that a contributor worked on this project. In Github, people usually contribute by forking the project
  - So the contributor's repos should be looked at to see if there is a fork of this repo
- After knowing that you should look at the forks, you can go to Insights tab > Forks > Switch to tree view (list view is broken for some reason) > see cranetributor16/crane-api as a repo
  - Inside [cranetributor16/crane-api](https://github.com/cranetributor16/crane-api), the .env file is still there
  - Look inside .env, get API_KEY

Flag: ```csd{M11174rY_6r4D3_H1570rY}```

</details>

Write-up by [GodderE2D](https://godder.xyz)