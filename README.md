<p align=center>
  <img alt="Project's status" src="https://img.shields.io/github/last-commit/kema-dev/push_swap?logo=github">
  <img alt="Project's primary language" src="https://img.shields.io/badge/Language-C-blue">
  <img alt="Project's focus" src="https://img.shields.io/badge/Focus-Sorting%20algorithm-blue">
</p>

# push_swap

push_swap is a 42 project consisting in the making of some sort of a stack sorting algorithm in C.

Full subject is available [here](docs/)

Use this command to visualize the sorting, generating random numbers with ruby

```sh
python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
```

Use this command to check the validity of the program, generating random numbers with ruby

```sh
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l && ./push_swap $ARG | ./checker_Mac $ARG
```
