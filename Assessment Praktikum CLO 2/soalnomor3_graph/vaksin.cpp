#include "vaksin.h"

// Inisialisasi Graph
void createGraph(Graph &G) {
    G.firstNode = NULL;
}

// Alokasi Node Baru
Node* alokasiNode(string id) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->isLockedDown = false; // Default: Aman
    newNode->visited = false;
    newNode->firstEdge = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

// Menambahkan Node ke dalam Graph
void addNode(Graph &G, string id) {
    Node* newNode = alokasiNode(id);
    if (G.firstNode == NULL) {
        G.firstNode = newNode;
    } else {
        // Insert Last
        Node* curr = G.firstNode;
        while (curr->nextNode != NULL) {
            curr = curr->nextNode;
        }
        curr->nextNode = newNode;
    }
}

// Mencari Node berdasarkan ID (Nama Kota)
Node* findNode(Graph G, string id) {
    Node* curr = G.firstNode;
    while (curr != NULL) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->nextNode;
    }
    return NULL;
}

// Menambahkan Edge (Undirected / Dua Arah)
void addEdge(Graph &G, string src, string dest) {
    Node* srcNode = findNode(G, src);
    Node* destNode = findNode(G, dest);

    if (srcNode != NULL && destNode != NULL) {
        // 1. Tambahkan Edge dari Source -> Dest
        Edge* newEdge1 = new Edge;
        newEdge1->destNode = destNode;
        newEdge1->nextEdge = srcNode->firstEdge; // Insert First pada list edge
        srcNode->firstEdge = newEdge1;

        // 2. Tambahkan Edge dari Dest -> Source (Karena Undirected)
        Edge* newEdge2 = new Edge;
        newEdge2->destNode = srcNode;
        newEdge2->nextEdge = destNode->firstEdge; // Insert First pada list edge
        destNode->firstEdge = newEdge2;
    }
}

// Helper: Menampilkan Graph
void printGraph(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    Node* curr = G.firstNode;
    while (curr != NULL) {
        cout << "Node " << curr->id << " terhubung ke: ";
        Edge* e = curr->firstEdge;
        if (e == NULL) cout << "-";
        while (e != NULL) {
            cout << e->destNode->id << " ";
            e = e->nextEdge;
        }
        cout << endl;
        curr = curr->nextNode;
    }
    cout << endl;
}

// --- LOGIKA SIMULASI ---

// Reset status visited sebelum DFS baru
void resetVisited(Graph &G) {
    Node* curr = G.firstNode;
    while (curr != NULL) {
        curr->visited = false;
        curr = curr->nextNode;
    }
}

// Hitung jumlah node yang sedang AKTIF (tidak dilockdown)
int countActiveNodes(Graph G) {
    int count = 0;
    Node* curr = G.firstNode;
    while (curr != NULL) {
        if (!curr->isLockedDown) {
            count++;
        }
        curr = curr->nextNode;
    }
    return count;
}

// Depth First Search (Traversal)
// Hanya mengunjungi node yang TIDAK dilockdown
void dfs(Node* u, int &countVisited) {
    u->visited = true;
    countVisited++;

    Edge* e = u->firstEdge;
    while (e != NULL) {
        Node* v = e->destNode;
        // Kunjungi tetangga jika:
        // 1. Belum dikunjungi
        // 2. Tetangga tersebut TIDAK sedang dilockdown
        if (!v->visited && !v->isLockedDown) {
            dfs(v, countVisited);
        }
        e = e->nextEdge;
    }
}

// Cek apakah Graph terhubung utuh (selain node yang dilockdown)
bool isGraphConnected(Graph G) {
    resetVisited(G);
    
    // Cari titik awal traversal (node pertama yang tidak lockdown)
    Node* startNode = G.firstNode;
    while (startNode != NULL && startNode->isLockedDown) {
        startNode = startNode->nextNode;
    }

    // Jika semua node dilockdown (atau graph kosong), anggap terhubung (trivial)
    if (startNode == NULL) return true;

    // Lakukan DFS dari startNode
    int nodesReached = 0;
    dfs(startNode, nodesReached);

    // Bandingkan jumlah node yang berhasil dikunjungi dengan jumlah node aktif
    int totalActive = countActiveNodes(G);
    
    return nodesReached == totalActive;
}

// Fungsi Utama: Analisis Titik Kritis
void analisisKotaKritis(Graph G) {
    cout << "Analisis Kota Kritis (Single Point of Failure)" << endl;
    
    Node* curr = G.firstNode;
    while (curr != NULL) {
        // 1. SIMULASI: Lockdown node ini
        curr->isLockedDown = true;

        // 2. CEK: Apakah sisa graph masih terhubung?
        bool connected = isGraphConnected(G);

        // 3. REPORT
        if (connected) {
            cout << "Kota " << curr->id << " aman (redundansi oke)." << endl;
        } else {
            cout << "[PERINGATAN] Kota " << curr->id << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << curr->id << " lockdown, distribusi terputus." << endl;
        }

        // 4. RESTORE: Buka kembali lockdown untuk iterasi selanjutnya
        curr->isLockedDown = false;

        curr = curr->nextNode;
    }
}