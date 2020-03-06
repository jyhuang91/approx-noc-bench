Approx-NoC Benchmarks
==========================================

The annoated benchmarks used in Approx-NoC [1] are from PARSEC [2] and
SSCA2v2.2 [3], we include them here for reference.

The approximation regions are annoated through dummy functions
`registerApproxRegion()` and `deregisterApproxRegion()` that can be hooked by
pin tools. We show case this utility using ZSim (included in
`hooks/zsim_hooks.h`). A callback function in pin tool can record the region
and later manipulate the data in these memory regions for functional
simulation.

Pin-based performance simulator can directly run it to account for performance
effect.

For gem5 simulations, it may be a bit tedious. Firstly, these applications
should be compiled with PARSEC hooks and run to get a checkpoint. During
checkpoint creation, the approximated regions (in virtual addresses) are
printed, which should be dumped to a file. Later when resuming the simulation
from the checkpoint, load the regions through the file. When memory accesses
happens, the virtual address of the block should be passed along with the
physical address in the system so that you can identify the approximability of
the data block based on its virtual address. (But hacking gem5's ruby memory
system and slicc for coherence is painful.)

### References

[1] Rahul Boyapati, Jiayi Huang, Pritam Majumder, Ki Hwan Yum, Eun Jung Kim,
2017. [APPROX-NoC: A Data Approximation Framework for Network-On-Chip
Architectures](https://jyhuang91.github.io/papers/isca2017-approxnoc.pdf). In
Proceedings of ISCA ’17, Toronto, ON, Canada, June 24-28, 2017, 12 pages.

[2] Christian Bienia, Sanjeev Kumar, Jaswinder Pal Singh, and Kai Li. 2008. The
PARSEC benchmark suite: characterization and architectural implications. In
Proceedings of the 17th international conference on Parallel architectures and
compilation techniques (PACT ’08). Association for Computing Machinery, New
York, NY, USA, 72–81.

[3] D.A. Bader and K. Madduri, "Design and Implementation of the HPCS Graph
Analysis Benchmark on Symmetric Multiprocessors," The 12th International
Conference on High Performance Computing (HiPC 2005), D.A. Bader et al.,
(eds.), Springer-Verlag LNCS 3769, 465-476, Goa, India, December 2005.

---

If you find this useful in your research, please consider citing the paper:

    @inproceedings{isca2017_approxnoc,
     author = {Boyapati, Rahul and Huang, Jiayi and Majumder, Pritam and Kim, Ki Hwawn and Kim, Eun Jung},
     title = {{Approx-NoC: A Data Approximation Framework for Network-On-Chip Architectures}},
     booktitle = {Proceedings of the 44th International Symposium on Computer Architecture (ISCA-44)},
     pages = {666--677},
     month = {July},
     year = {2017}
    }
