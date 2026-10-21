name: Build Geode Mod

on:
  push:
    branches: [ "main", "master" ]
  pull_request:
    branches: [ "main", "master" ]

jobs:
  build:
    name: Build Android
    runs-on: ubuntu-22.04

    steps:
      - name: Checkout code
        uses: actions/checkout@v4

      - name: Setup CLI & Build
        run: |
          wget https://github.com/geode-sdk/cli/releases/latest/download/geode-cli-linux.zip -O geode.zip
          unzip geode.zip -d ~/.geode/bin
          chmod +x ~/.geode/bin/geode
          ~/.geode/bin/geode --version
          ~/.geode/bin/geode package build --target android64 --target android32
