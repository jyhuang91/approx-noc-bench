#include "defs.h"

double parseGraph(graphSDG* SDGdata, FILE* graph_fp) {

    VERT_T *src, *dest;
    WEIGHT_T *wt;
    LONG_T n, m;
    VERT_T *permV;
    char line[256];
#ifdef _OPENMP
    omp_lock_t* vLock;
#endif

    double elapsed_time;
    int seed;

    n = N;
    m = M;

    /* allocate memory for edge tuples */
    src  = (VERT_T *) malloc(M*sizeof(VERT_T));
    dest = (VERT_T *) malloc(M*sizeof(VERT_T));
    assert(src  != NULL);
    assert(dest != NULL);

    /* sprng seed */
    seed = 2387;
    //seed = 2398;

    elapsed_time = get_seconds();

    int i = 0;
	while (fgets(line, sizeof(line), graph_fp) && i < m) {
		if (line[0] == '#')	continue;
		int src_m, dest_m;
		sscanf(line, "%d\t%d\n", &src_m, &dest_m);
		//printf("%d\t%d\n", src_m, dest_m);
		src[i]  = src_m;
		dest[i] = dest_m;
        i++;
	}

#ifdef _OPENMP
#if PARALLEL_SDG
    omp_set_num_threads(omp_get_max_threads());
    // omp_set_num_threads(16);
#else
    omp_set_num_threads(1);
#endif
#endif

#ifdef _OPENMP
#pragma omp parallel
{
#endif
    int tid, nthreads;
    int *stream;

#ifdef _OPENMP
    nthreads = omp_get_num_threads();
    tid = omp_get_thread_num();
#else
    nthreads = 1;
    tid  = 0;
#endif

    /* Initialize RNG stream */
	stream = init_sprng(0, tid, nthreads, seed, SPRNG_DEFAULT);

    /* Generate edge weights */
    if (tid == 0) {
        wt = (WEIGHT_T *) malloc(M*sizeof(WEIGHT_T));
        assert(wt != NULL);
    }

#ifdef _OPENMP
#pragma omp barrier

#pragma omp for
#endif
    for (i=0; i<m; i++) {
        wt[i] = 1 + MaxIntWeight * sprng(stream);
    }

    SDGdata->n = n;
    SDGdata->m = m;
    SDGdata->startVertex = src;
    SDGdata->endVertex = dest;
    SDGdata->weight = wt;

    free_sprng(stream);
#ifdef _OPENMP
}
#endif

//    FILE * graph = fopen("out_graph.txt", "w");
//    if (!graph) exit(0);
//    unsigned j;
//    printf("Nodes: %d, Edges: %d\n", n, m);
//    for (j = 0; j < m; j++) {
//        fprintf(graph, "%d\t%d\n", src[j], dest[j]);
//    }
//    fclose(graph);

    elapsed_time = get_seconds() - elapsed_time;
    return elapsed_time;
}
