#include <bits/stdc++.h>
using namespace std;
string bcode, dir, l1, l2, l3;
int cntid, cntii, l4;
bool cntip;

struct fil {
	string name, place;
	bool isfolder;
};

struct folders {
	string place;
};

struct wdfile {
	string name, place;
	vector<string> vep;
};

bool filcmp(fil ay, fil by) {
	if (ay.place != by.place)  return ay.place < by.place;
	if (ay.isfolder != by.isfolder)  return ay.isfolder > by.isfolder;
	return ay.name < by.name;
}

bool folcmp(folders ay, folders by) {
	return ay.place < by.place;
}

vector<fil> vfile;
vector<folders> vfolder;
vector<wdfile> vftp;

void pe(auto xpe) {
	cout << xpe << endl;
}

void p(auto xp) {
	cout << xp;
}

void getdata(string dirs, int dar) {
	cntip = false;
	string ceng = "";
	for (int i = 1; i <= dar; i++) {
		ceng = "  " + ceng;
	}
	if (dar > 0)  ceng = ceng + " ";
	for (int i = 0; i < vfile.size(); i++) {
		if (vfile[i].place == dirs) {
			cntip = true;
			if (vfile[i].isfolder) {
				pe(ceng + vfile[i].name + "{");
				getdata(dirs + vfile[i].name + "/", dar + 1);
				pe(ceng + "}");
			} else {
				pe(ceng + vfile[i].name);
			}
		} else if (cntip) {
			break;
		}
	}
}

void hr(int xhr, bool is) {
	if (!is)  for (int i = 1; i <= xhr; i++)  cout << endl;
	else  for (int i = 1; i <= xhr; i++)  cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void seekdir(string ddir) {
	for (int i = 0; i < vfile.size(); i++) {
		if (vfile[i].place == ddir and vfile[i].isfolder) {
			cntii++;
		} else if (vfile[i].place == ddir) {
			cntid++;
		}
	}
}

void pn(string adir, string bname) {
	for (int i = 0; i < vftp.size(); i++) {
		if (vftp[i].place == adir and vftp[i].name == bname) {
			pe(vftp[i].vep.size());
			for (int j = 0; j < vftp[i].vep.size(); j++) {
				pe(vftp[i].vep[j]);
			}
			break;
		}
	}
}

void findfiles(string pd) {
	for (int i = 0; i < vfile.size(); i++) {
		if (vfile[i].place == pd and vfile[i].isfolder) {
			cntii++;
			findfiles(pd + vfile[i].name + "/");
		} else if (vfile[i].place == pd) {
			cntid++;
		}
	}
}

void readycode() {
	pe(R"(________  _______  ___    _______       _______ ______   _______ _______ _______ _____           ___   ___  ______       ____  )");
	pe(R"(| _____|  |_   _|  | |    | ____|       | ____| | ___ \  |_   _| |_   _| | ____| | __ \          | |   | | / ____ \     /_  |  )");
	pe(R"(| |_____    | |    | |    | |____       | |____ | |  \ \   | |     | |   | |____ | | \ \         | |   | | | |  | |       | |  )");
	pe(R"(| _____|    | |    | |    | ____|       | ____| | |  | |   | |     | |   | ____| | |_| |         \ \   / / | |  | |       | |  )");
	pe(R"(| |        _| |_   | |___ | |____       | |____ | |__/ /  _| |_    | |   | |____ |  __ \          \ \_/ /  | |__| | ___  _| |_ )");
	pe(R"(|_|       |_____|  |____| |_____|       |_____| |_____/  |_____|   |_|   |_____| |_|  \_|          \___/   \______/ |_| |_____|)");
	hr(1, false);
	hr(1, true);
	hr(1, false);
}

void codenames() {
	pe("help     |                                       help");
	pe("runtime  |                                get runtime");
	pe("clr      |                               clear screen");
	pe("pc       |                                 see folder");
	pe("mkfil    |                                  make file");
	pe("mkdir    |                                make folder");
	pe("del      |                         delete file/folder");
	pe("tree     |                             view file tree");
	pe("tnum     |             get this dir's number of files");
	pe("anum     |  get this dir and subdir's number of files");
	pe("use      |                              change a file");
	pe("oup      |                      download file package");
	pe("inp      |                         input file package");
	pe("hr       |                                make a line");
	pe("p        |                            make a new line");
	pe("chg      |                    change file/folder name");
	pe("put      |                               mobile files");
	pe("end      |                             end management");
}

void yed(string st, string et, string what) {
	for (int i = 0; i < vfile.size(); i++) {
		if (vfile[i].place == st and vfile[i].name == what) {
			vfile[i].place = et;
			if (vfile[i].isfolder) {
				for (int j = 0; j < vfile.size(); j++) {
					if (vfile[j].place == (st + what + "/")) {
						yed(st + what + "/", et + what + "/", vfile[j].name);
					}
				}
			}
			break;
		}
	}
}

int main() {
	readycode();
	vfolder.push_back({"All/"});
	while (true) {
		p(">>>");
		cin >> bcode;
		if (bcode == "help") {
			codenames();
		} else if (bcode == "runtime") {
			cout << double(clock()) / CLOCKS_PER_SEC << endl;
		} else if (bcode == "clr") {
			system("cls");
			readycode();
		} else if (bcode == "pc") {
			cin >> dir;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
			else {
				sort(vfile.begin(), vfile.end(), filcmp);
				sort(vfolder.begin(), vfolder.end(), folcmp);
				pe(dir + ":");
				cntip = false;
				for (int i = 0; i < vfile.size(); i++) {
					if (vfile[i].place == dir) {
						cntip = true;
						if (vfile[i].isfolder) {
							pe("folder " + vfile[i].name);
						} else {
							pe("file " + vfile[i].name);
						}
					} else if (cntip) {
						break;
					}
				}
			}
		} else if (bcode == "put") {
			cin >> dir >> l1 >> l2;
			yed(dir, l2, l1);
		} else if (bcode == "mkfil") {
			cin >> dir >> l1;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					vfile.push_back({l1, dir, false});
					vftp.push_back({l1, dir, {}});
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
		} else if (bcode == "mkdir") {
			cin >> dir >> l1;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					vfile.push_back({l1, dir, true});
					vfolder.push_back({dir + l1 + "/"});
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
		} else if (bcode == "del") {
			cin >> dir >> l1;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
			else {
				cntip = true;
				for (int i = 0; i < vfile.size(); i++) {
					if (vfile[i].place == dir and vfile[i].name == l1) {
						if (vfile[i].isfolder) {
							for (int j = 0; j < vfolder.size(); j++) {
								if ((vfolder[j].place.find(dir + l1 + "/") != -1) and (vfolder[j].place.size() >= (dir + l1 + "/").size())) {
									vfolder.erase(vfolder.begin() + j);
								}
							}
						} else {
							for (int j = 0; j < vftp.size(); j++) {
								if (vftp[j].place == dir and vftp[j].name == l1) {
									vftp.erase(vftp.begin() + j);
									break;
								}
							}
						}
						vfile.erase(vfile.begin() + i);
						cntip = false;
						break;
					}
				}
				if (cntip)  pe("Can not found this file!");
			}
		} else if (bcode == "tree") {
			cin >> dir;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
			else {
				sort(vfile.begin(), vfile.end(), filcmp);
				sort(vfolder.begin(), vfolder.end(), folcmp);
				pe(dir + ":");
				getdata(dir, 0);
			}
		} else if (bcode == "tnum") {
			cin >> dir;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
			else {
				cntip = true, cntid = 0, cntii = 0;
				sort(vfile.begin(), vfile.end(), filcmp);
				sort(vfolder.begin(), vfolder.end(), folcmp);
				findfiles(dir);
				pe("files count: " + to_string(cntid));
				pe("folders count: " + to_string(cntii));
				pe("all: " + to_string(cntid + cntii));
			}
		}  else if (bcode == "anum") {
			cin >> dir;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
			else {
				cntip = true, cntid = 0, cntii = 0;
				sort(vfile.begin(), vfile.end(), filcmp);
				sort(vfolder.begin(), vfolder.end(), folcmp);
				seekdir(dir);
				pe("files count: " + to_string(cntid));
				pe("folders count: " + to_string(cntii));
				pe("all: " + to_string(cntid + cntii));
			}
		} else if (bcode == "use") {
			cin >> dir >> l1;
			pe("Editing mode");
			system("pause");
			while (true) {
				system("cls");
				readycode();
				cntip = true;
				for (int i = 0; i < vftp.size(); i++) {
					if (vftp[i].name == l1 and vftp[i].place == dir) {
						cntip = false, cntid = i;
						break;
					}
				}
				pe("Now editing: " + dir + l1 + "/");
				if (cntip) {
					pe("Can not found this folder!");
					break;
				} else {
					for (int i = 0; i < vftp[cntid].vep.size(); i++) {
						pe(to_string(i + 1) + " " + vftp[cntid].vep[i]);
					}
					hr(1,false);
					hr(1,true);
					hr(1,false);
				}
				p(">>");
				cin >> l2;
				if (l2 == "help" or l2 == "h") {
					pe("help  |                  help");
					pe("h     |                  help");
					pe("w     |        write new line");
					pe("d     |           delete line");
					pe("a     |             all clear");
					pe("c     |         change a line");
					pe("f     |  change the edit file");
					pe("/     |     exit editing mode");
				} else if (l2 == "w") {
					getline(cin, l3);
					vftp[cntid].vep.push_back(l3);
				} else if (l2 == "d") {
					cin >> l4;
					vftp[cntid].vep.erase(vftp[cntid].vep.begin() + l4 - 1);
				} else if (l2 == "a") {
					vftp[cntid].vep.clear();
				} else if (l2 == "c") {
					cin >> l4 >> l3;
					vftp[cntid].vep[l4] = l3;
				} else if (l2 == "f") {
					cin >> dir >> l1;
					pe("Choose: " + dir + l1 + "/");
				} else if (l2 == "/") {
					break;
				} else {
					pe("Can't find this code,");
					pe("You can use code <help>,to search your true code.");
				}
				system("pause");
			}
			pe("Break Editing mode");
			system("pause");
			system("cls");
			readycode();
		} else if (bcode == "oup") {
			cin >> dir;
			cntid = 0;
			freopen("File.txt", "w", stdout);
			sort(vfile.begin(), vfile.end(), filcmp);
			sort(vfolder.begin(), vfolder.end(), folcmp);
			for (int i = 0; i < vfile.size(); i++) {
				if ((vfile[i].place.find(dir) != -1)) {
					cntid++;
				}
			}
			pe(cntid);
			for (int i = 0; i < vfile.size(); i++) {
				if ((vfile[i].place.find(dir) != -1)) {
					if (vfile[i].isfolder) {
						pe(vfile[i].place + " " + vfile[i].name + " 1");
					} else {
						pe(vfile[i].place + " " + vfile[i].name + " 0");
						pn(vfile[i].place, vfile[i].name);
					}
				}
			}
			freopen("CON", "w", stdout);
		} else if (bcode == "inp") {
			freopen("File.txt", "r", stdin);
			cin >> cntid;
			vfile.clear();
			vfolder.clear();
			vftp.clear();
			vfolder.push_back({"All/"});
			for (int i = 1; i <= cntid; i++) {
				cin >> l1 >> l2 >> cntip;
				vfile.push_back({l2, l1, cntip});
				if (cntip) {
					vfolder.push_back({l1});
				} else {
					vftp.push_back({l2, l1, {}});
					cin >> l4;
					getchar();
					for (int j = 1; j <= l4; j++) {
						getline(cin, l3);
						vftp[vftp.size() - 1].vep.push_back(l3);
					}
				}
			}
			freopen("CON", "r", stdin);
		} else if (bcode == "hr") {
			hr(1, true);
		} else if (bcode == "p") {
			hr(1, false);
		} else if (bcode == "chg") {
			cin >> dir >> l1 >> l2;
			cntip = true;
			for (int i = 0; i < vfolder.size(); i++) {
				if (vfolder[i].place == dir) {
					cntip = false;
					break;
				}
			}
			if (cntip)  pe("Can not found this folder!");
			else {
				cntip = true;
				for (int i = 0; i < vfile.size(); i++) {
					if (vfile[i].place == dir and vfile[i].name == l1) {
						vfile[i].name = l2;
						cntip = false;
						break;
					}
				}
				if (cntip)  pe("Can not found this file!");
			}
		} else if (bcode == "end") {
			system("pause");
			exit(0);
		} else {
			pe("Can't find this code,");
			pe("You can use code <help>,to search your true code.");
		}
	}
	return 0;
}
