*This project has been created as part of the 42 curriculum by msuter.*

# Philosophers

## Description

The Dining Philosophers problem is a classic concurrency problem. N philosophers sit around a table, each needing two forks to eat. Since forks are shared between neighbors (N philosophers, N forks), the challenge is to ensure every philosopher eats before dying, without two philosophers using the same fork simultaneously.

Each philosopher cycles through three states: eating, sleeping, and thinking.

## Implementation

- One thread per philosopher
- One mutex per fork
- A monitor thread checking for deaths and simulation end
- A `p_running` mutex to safely share simulation state
- A `logs` mutex to prevent mixed output messages
- Even-numbered philosophers sleep first at startup to avoid deadlocks

## Instructions

```bash
make          # compile
make clean    # remove object files
make fclean   # remove all generated files
make re       # recompile from scratch
```

```bash
./philo nb_philo time_to_die time_to_eat time_to_sleep [nb_must_eat]
```

| Argument | Description |
|---|---|
| `nb_philo` | Number of philosophers |
| `time_to_die` | Time in ms before a philosopher dies without eating |
| `time_to_eat` | Time in ms a philosopher takes to eat |
| `time_to_sleep` | Time in ms a philosopher sleeps |
| `nb_must_eat` | (Optional) Simulation stops when all philosophers have eaten this many times |

## Examples

```bash
# Small cases
./philo 1 800 200 200      # philosopher 0 must die
./philo 5 800 200 200      # no philosopher should die
./philo 5 800 200 200 7    # no philosopher dies, simulation stops after 7 meals each
./philo 4 410 200 200      # no philosopher should die
./philo 4 310 200 100      # one philosopher must die
./philo 2 800 200 200      # no philosopher dies, death detected in under 10ms

# Large cases
./philo 50 800 200 200     # no philosopher should die
./philo 100 800 200 200    # no philosopher should die
./philo 150 800 200 200    # no philosopher should die
./philo 200 800 200 200    # no philosopher should die
./philo 50 800 200 200 10  # no philosopher dies, simulation stops after 10 meals each
./philo 100 800 200 200 5  # no philosopher dies, simulation stops after 5 meals each
```

## Resources

- [CodeVault — Threads playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) — used to understand POSIX threads and mutexes
- Claude (Anthropic) — used strictly for concept clarification and debugging guidance, never for code generation
