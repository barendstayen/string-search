# Tests
## Data small
### 1 Tread
```bash
Pattern: "parallel" Count: 2 Time: 0.83695 ms
Pattern: "pattern" Count: 2 Time: 0.354742 ms
Pattern: "search" Count: 1 Time: 0.316691 ms
Pattern: "algorithm" Count: 1 Time: 0.356085 ms
Pattern: "text" Count: 2 Time: 0.355003 ms
Pattern: "cpu" Count: 0 Time: 0.280794 ms
Pattern: "data" Count: 1 Time: 0.378757 ms
Pattern: "string" Count: 1 Time: 0.298597 ms
Pattern: "partition" Count: 1 Time: 0.337059 ms
Pattern: "worker" Count: 1 Time: 0.309127 ms
Pattern: "overlap" Count: 0 Time: 0.315399 ms
Pattern: "boundary" Count: 0 Time: 0.601303 ms
```

### 2 Treads
```bash
Pattern: "parallel" Count: 2 Time: 0.887118 ms
Pattern: "pattern" Count: 2 Time: 3.86772 ms
Pattern: "search" Count: 1 Time: 5.10707 ms
Pattern: "algorithm" Count: 1 Time: 2.82194 ms
Pattern: "text" Count: 2 Time: 4.01155 ms
Pattern: "cpu" Count: 0 Time: 5.20454 ms
Pattern: "data" Count: 1 Time: 3.67045 ms
Pattern: "string" Count: 1 Time: 6.89013 ms
Pattern: "partition" Count: 1 Time: 2.31634 ms
Pattern: "worker" Count: 1 Time: 3.92025 ms
Pattern: "overlap" Count: 0 Time: 5.68427 ms
Pattern: "boundary" Count: 0 Time: 3.61681 ms
```


### 4 Treads
```bash
Pattern: "parallel" Count: 2 Time: 4.29284 ms
Pattern: "pattern" Count: 2 Time: 4.84153 ms
Pattern: "search" Count: 1 Time: 8.05643 ms
Pattern: "algorithm" Count: 1 Time: 6.36132 ms
Pattern: "text" Count: 2 Time: 4.6031 ms
Pattern: "cpu" Count: 0 Time: 6.36128 ms
Pattern: "data" Count: 1 Time: 6.03277 ms
Pattern: "string" Count: 1 Time: 5.6081 ms
Pattern: "partition" Count: 1 Time: 6.43958 ms
Pattern: "worker" Count: 1 Time: 8.3668 ms
Pattern: "overlap" Count: 0 Time: 6.20752 ms
Pattern: "boundary" Count: 0 Time: 5.09433 ms
```
## Data Medium
### 1 Tread
```bash
Pattern: "parallel" Count: 6 Time: 0.406168 ms
Pattern: "pattern" Count: 4 Time: 1.43722 ms
Pattern: "search" Count: 5 Time: 0.32666 ms
Pattern: "algorithm" Count: 2 Time: 0.68015 ms
Pattern: "text" Count: 6 Time: 1.38126 ms
Pattern: "cpu" Count: 0 Time: 0.597456 ms
Pattern: "data" Count: 9 Time: 1.35459 ms
Pattern: "string" Count: 0 Time: 0.928864 ms
Pattern: "partition" Count: 1 Time: 0.245679 ms
Pattern: "worker" Count: 6 Time: 0.250298 ms
Pattern: "overlap" Count: 2 Time: 1.24581 ms
Pattern: "boundary" Count: 3 Time: 0.93204 ms
```

### 2 Treads
```bash
Pattern: "parallel" Count: 6 Time: 0.971655 ms
Pattern: "pattern" Count: 4 Time: 2.10101 ms
Pattern: "search" Count: 5 Time: 4.77265 ms
Pattern: "algorithm" Count: 2 Time: 1.76842 ms
Pattern: "text" Count: 6 Time: 2.66864 ms
Pattern: "cpu" Count: 0 Time: 3.44933 ms
Pattern: "data" Count: 9 Time: 3.81363 ms
Pattern: "string" Count: 0 Time: 4.24562 ms
Pattern: "partition" Count: 1 Time: 2.82573 ms
Pattern: "worker" Count: 6 Time: 2.64901 ms
Pattern: "overlap" Count: 2 Time: 3.90707 ms
Pattern: "boundary" Count: 3 Time: 3.36106 ms
```


### 4 Treads
```bash
Pattern: "parallel" Count: 6 Time: 1.71085 ms
Pattern: "pattern" Count: 4 Time: 4.79699 ms
Pattern: "search" Count: 5 Time: 5.48012 ms
Pattern: "algorithm" Count: 2 Time: 6.64783 ms
Pattern: "text" Count: 6 Time: 3.58396 ms
Pattern: "cpu" Count: 0 Time: 5.59108 ms
Pattern: "data" Count: 9 Time: 6.25167 ms
Pattern: "string" Count: 0 Time: 3.9632 ms
Pattern: "partition" Count: 1 Time: 4.78197 ms
Pattern: "worker" Count: 6 Time: 5.24601 ms
Pattern: "overlap" Count: 2 Time: 7.12481 ms
Pattern: "boundary" Count: 3 Time: 5.08557 ms
```

## Data Large
### 1 Tread
```bash
Pattern: "parallel" Count: 6 Time: 0.966204 ms
Pattern: "pattern" Count: 10 Time: 1.48985 ms
Pattern: "search" Count: 11 Time: 0.675992 ms
Pattern: "algorithm" Count: 3 Time: 0.99626 ms
Pattern: "text" Count: 8 Time: 0.559765 ms
Pattern: "cpu" Count: 0 Time: 0.451773 ms
Pattern: "data" Count: 10 Time: 0.629144 ms
Pattern: "string" Count: 3 Time: 1.9906 ms
Pattern: "partition" Count: 4 Time: 1.63246 ms
Pattern: "worker" Count: 9 Time: 2.22864 ms
Pattern: "overlap" Count: 4 Time: 1.01798 ms
Pattern: "boundary" Count: 3 Time: 1.93477 ms
```

### 2 Treads
```bash
Pattern: "parallel" Count: 6 Time: 0.700197 ms
Pattern: "pattern" Count: 10 Time: 2.68574 ms
Pattern: "search" Count: 11 Time: 2.03591 ms
Pattern: "algorithm" Count: 3 Time: 2.2946 ms
Pattern: "text" Count: 8 Time: 3.45743 ms
Pattern: "cpu" Count: 0 Time: 0.90008 ms
Pattern: "data" Count: 10 Time: 3.10919 ms
Pattern: "string" Count: 3 Time: 2.17609 ms
Pattern: "partition" Count: 4 Time: 3.08094 ms
Pattern: "worker" Count: 9 Time: 3.15328 ms
Pattern: "overlap" Count: 4 Time: 2.41062 ms
Pattern: "boundary" Count: 3 Time: 1.81305 ms
```


### 4 Treads
```bash
Pattern: "parallel" Count: 6 Time: 2.60222 ms
Pattern: "pattern" Count: 10 Time: 3.38432 ms
Pattern: "search" Count: 11 Time: 4.88788 ms
Pattern: "algorithm" Count: 3 Time: 8.84539 ms
Pattern: "text" Count: 8 Time: 8.98633 ms
Pattern: "cpu" Count: 0 Time: 6.16362 ms
Pattern: "data" Count: 10 Time: 5.16559 ms
Pattern: "string" Count: 3 Time: 7.56483 ms
Pattern: "partition" Count: 4 Time: 6.16749 ms
Pattern: "worker" Count: 9 Time: 7.43526 ms
Pattern: "overlap" Count: 4 Time: 10.259 ms
Pattern: "boundary" Count: 3 Time: 3.24679 ms
```