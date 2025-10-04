#include <bits/stdc++.h>
using namespace std;

double closestMoment(
    double xs, double ys, double xe, double ye,
    double as, double ay, double ae, double aey
) {
    double dxT = xe - xs, dyT = ye - ys;
    double lenT = hypot(dxT, dyT);
    double dxA = ae - as, dyA = aey - ay;
    double lenA = hypot(dxA, dyA);

    double t1 = lenT, t2 = lenA;

    double vxT = dxT / lenT, vyT = dyT / lenT;
    double vxA = dxA / lenA, vyA = dyA / lenA;

    vector<double> times = {0.0, t1, t2};

    double vx = vxT - vxA, vy = vyT - vyA;
    double x0 = xs - as, y0 = ys - ay;
    double denom = vx * vx + vy * vy;

    if (denom > 1e-14) {
        double tCrit = -(x0 * vx + y0 * vy) / denom;
        if (tCrit >= 0 && tCrit <= min(t1, t2)) times.push_back(tCrit);
    }

    if (t1 < t2) {
        double vx_ = vxA, vy_ = vyA;
        double x_ = as - xe, y_ = ay - ye;
        double denom2 = vx_ * vx_ + vy_ * vy_;
        if (denom2 > 1e-14) {
            double tCrit = -((x_ * vx_) + (y_ * vy_)) / denom2;
            if (tCrit >= t1 && tCrit <= t2) times.push_back(tCrit);
        }
    } else if (t2 < t1) {
        double vx_ = vxT, vy_ = vyT;
        double x_ = xs - ae, y_ = ys - aey;
        double denom2 = vx_ * vx_ + vy_ * vy_;
        if (denom2 > 1e-14) {
            double tCrit = -((x_ * vx_) + (y_ * vy_)) / denom2;
            if (tCrit >= t2 && tCrit <= t1) times.push_back(tCrit);
        }
    }

    double minDist = 1e18;
    for (double t : times) {
        double tx = (t <= t1) ? xs + vxT * t : xe;
        double ty = (t <= t1) ? ys + vyT * t : ye;
        double ax = (t <= t2) ? as + vxA * t : ae;
        double ay_ = (t <= t2) ? ay + vyA * t : aey;
        double dist = hypot(tx - ax, ty - ay_);
        if (dist < minDist) minDist = dist;
    }
    return minDist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        double TSX, TSY, TGX, TGY, ASX, ASY, AGX, AGY;
        cin >> TSX >> TSY >> TGX >> TGY >> ASX >> ASY >> AGX >> AGY;
        double ans = closestMoment(TSX, TSY, TGX, TGY, ASX, ASY, AGX, AGY);
        cout << fixed << setprecision(15) << ans << "\n";
    }
    return 0;
}
