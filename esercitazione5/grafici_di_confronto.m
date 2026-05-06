tempi_debug = readtable("debug.csv");

xd = tempi_debug.Dim;
bubbled = tempi_debug.Bubblesort;
insertiond = tempi_debug.Insertionsort;
selectiond = tempi_debug.Selectionsort;
standardd = tempi_debug.Standardsort;
merged = tempi_debug.Mergesort;
quickd = tempi_debug.Quicksort;
quickottimod = tempi_debug.QuickOttimo;

tempi_release = readtable("release.csv");

xr = tempi_release.Dim;
bubbler = tempi_release.Bubblesort;
insertionr = tempi_release.Insertionsort;
selectionr = tempi_release.Selectionsort;
standardr = tempi_release.Standardsort;
merger = tempi_release.Mergesort;
quickr = tempi_release.Quicksort;
quickottimor = tempi_release.QuickOttimo;

figure;
semilogy(xd,bubbled,"LineWidth", 1.5);
hold on;
semilogy(xd,insertiond,"LineWidth", 1.5);
semilogy(xd,selectiond,"LineWidth", 1.5);
semilogy(xd,standardd,"LineWidth", 1.5);
semilogy(xd,merged,"LineWidth", 1.5);
semilogy(xd,quickd,"LineWidth", 1.5);
semilogy(xd,quickottimod,"LineWidth", 1.5);

grid on; 

xlabel("Dimensione");
ylabel("Tempo medio (s)")
title("confronto tra i sorting in modalità debug")

legend("Bubble Sort","Insertion Sort", "Selection Sort", "Standard Sort", "Merge Sort", "Quick Sort", "Quick Sort ottimo")
hold off;

figure;
semilogy(xr,bubbler,"LineWidth", 1.5);
hold on;
semilogy(xr,insertionr,"LineWidth", 1.5);
semilogy(xr,selectionr,"LineWidth", 1.5);
semilogy(xr,standardr,"LineWidth", 1.5);
semilogy(xr,merger,"LineWidth", 1.5);
semilogy(xr,quickr,"LineWidth", 1.5);
semilogy(xr,quickottimor,"LineWidth", 1.5);

grid on; 

xlabel("Dimensione");
ylabel("Tempo medio (s)")
title("confronto tra i sorting in modalità release")

legend("Bubble Sort","Insertion Sort", "Selection Sort", "Standard Sort", "Merge Sort", "Quick Sort", "Quick Sort ottimo")
hold off;