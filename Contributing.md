# Contributing to Zia

## Rules

- **NEVER push on `main` branch.**
- **ALWAYS use Pull Requests when adding new features or bug fix.** 

## Convention

### Branch names

Use the following convention for branch names

- `namespace/feature`

**Example** : `build/conan-configuration`

> Consider using relevant branch namespaces (`ecs`,`network`, `graphics`...)

### Commits

Follow that [guide](https://chris.beams.io/posts/git-commit/) to see how to write good commit message.

**Guidelines**:
  - Group Commits: Each commit should represent a meaningful change (e.g. implement
    feature X, fix bug Y, ...).

  - For instance, a PR should not look like _1) Add Feature X 2) Fix Typo 3) Changes to features X 5) Bugfix for feature X 6) Fix Linter 7) ..._<br>
    Instead, these commits should be squashed together into a single "Add Feature" commit.

  - Each commit should work on its own: it must compile, pass the linter and so on.

  - This makes life much easier when using `git log`, `git blame`, `git bisect`, etc.

  - For instance, when doing a `git blame` on a file to figure out why a change
    was introduced, it's pretty meaningless to see a _Fix linter_ commit message.
    "Add Feature X" is much more meaningful.

  - Use `git rebase main` to group commits together and rewrite their commit message

  - To add changes to the previous commit, use `git commit --amend -s`. This will
    change the last commit (amend) instead of creating a new commit.

  - Format: Use the imperative mood in the subject line: "If applied, this commit
    will `_your subject line here_`"

## GitHub workflow

The recommended workflow is to clone the repository from `EpitechPromo2024/B-YEP-500-PAR-5-1-zia-aurelien.boch` and open pull requests directly from the repository.

### 1 - Clone the repository

```sh
git clone git@github.com:EpitechPromo2024/B-YEP-500-PAR-5-1-zia-aurelien.boch
```

### 2 - Create a Pull Request

```sh
# Create a branch
git checkout -b mybranch

# Make changes to your branch
# ...

# Add your change
git add [filenames]

# Commit your change
git commit -s -m "Add new feature that will take us to Mars"

# Push your change
git push
```

### 3 - Retrieve update from main

```sh
# Go to main
git checkout main 

# Pull change
git pull

# Go to working branch
git checkout working-branch

# Rebase from main
git rebase main

# Apply rebase
git push -f
```

[Go back to README](./README.md)