name: Build Geode Mod

on:
  push:
    branches: [ "main", "master" ]
  pull_request:
    branches: [ "main", "master" ]

jobs:
  build:
    name: Build Android Mod
    runs-on: ubuntu-22.04

    steps:
      - name: Checkout code
        uses: actions/checkout@v4
        with:
          submodules: recursive

      - name: Install Geode CLI
        run: |
          mkdir -p ~/.geode/bin
          wget https://github.com/geode-sdk/cli/releases/latest/download/geode-cli-linux.zip -O geode.zip
          unzip geode.zip -d ~/.geode/bin
          chmod +x ~/.geode/bin/geode
          echo "$HOME/.geode/bin" >> $GITHUB_PATH

      - name: Build Mod for Android
        run: |
          geode --version
          geode package build --target android64 --target android32
