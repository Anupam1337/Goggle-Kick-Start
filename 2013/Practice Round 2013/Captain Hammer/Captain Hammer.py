from decimal import Decimal
from math import asin, pi

T = int(input())
for t in range(1, T + 1):
    V, D = map(Decimal, input().split())
    val = Decimal(9.8) * D / (V ** 2)
    if val > 1:
        val = 1
    elif val < -1:
        val = -1
    θ = 90 * asin(val) / pi
    print(f"Case #{t}: {θ:.7f}", flush=True)
