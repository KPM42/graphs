    vector<int> pl(n + 1, 0), pr(n + 1, 0), mt(n+1, 0), way(n + 1, 0);
    for (int row = 1; row <= n; row++) {
        mt[0] = row;
        vector<int> minv(n + 1, inf);
        vector<bool> used(n + 1, false);
        int col = 0;
        do {
            used[col] = true;
            int v = mt[col], delta = inf, nextcol;
            for (int i = 1; i <= n; i++) {
                if (used[i])
                    continue;
                int x = g[v][i] - pl[v] - pr[i];
                if (x < minv[i])
                    minv[i] = x, way[i] = col;
                if (minv[i] < delta)
                    delta = minv[i], nextcol = i;
            }
            for (int i = 0; i <= n; i++) {
                if (used[i])
                    pl[mt[i]] += delta, pr[i] -= delta;
                else
                    minv[i] -= delta;
            }
            col = nextcol;
        } while (mt[col] != 0);
        do {// Перетыкиваем mt, вершин, у которых меняли ребра(они все как раз лежат на way из col в 0)
            int nextcol = way[col];
            mt[col] = mt[nextcol];
            col = nextcol;
        } while (col);
    }

