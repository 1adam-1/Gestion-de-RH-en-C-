#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Utilisateur {
protected:
    string nomUtilisateur;
    string motDePasse;

public:
    Utilisateur(const string& nom, const string& motPasse) : nomUtilisateur(nom), motDePasse(motPasse) {}

    string getNomUtilisateur() const {
        return nomUtilisateur;
    }

    bool verifierMotDePasse(const string& motPasseATester) const {
        return motPasseATester == motDePasse;
    }
};

class Contrat {
private:
    string type;
    string dateDebut;
    float salaire;

public:
    Contrat(const string& t, string date, float s) : type(t), dateDebut(date), salaire(s) {}

    void afficherDetails() const {
        cout << "Type de contrat : " << type << ", Date de debut : " << dateDebut << "  Salaire : " << salaire << endl;
    }
    float getSalaire()  {
        return salaire;
    }

    string getType()  {
        return type;
    }
    
    string getDate(){
    	return dateDebut;
	}
};

class Prime {
private:
    string nom;
    float montant;

public:
    Prime(const string& n, float m) : nom(n), montant(m) {}

    void afficherDetails() const {
        cout << "Prime : " << nom << ", Montant : " << montant << endl;
    }
    float getMontant() const {
        return montant;
    }
    string getNom() const {
        return nom;
    }
};

class Departement;

class Employe : public Utilisateur {
private:
    string nom;
    vector<Departement> departements;
    Contrat contrat;
    vector<Prime> primes;

public:
    Employe(const string& nomUtil, const string& motPasse, const string& n, const Contrat& c) : Utilisateur(nomUtil, motPasse), nom(n), contrat(c) {}


    string getNom()  {
        return nom;
    }

    void ajouterDepartement(Departement dep);
    
    void afficherDepartements();
    
    void afficherContrat()  {
        cout << "Contrat de l'employe " << nom << " :" << endl;
        cout << "Type :"<<contrat.getType()<<endl;
        cout << "Date de debut :"<<contrat.getDate()<<endl;
        cout << "Salaire :"<<contrat.getSalaire()<<endl;
        }
    
    
    void afficherPrimes() {
    cout << "Primes de l'employe " << getNom() << " :" << endl;
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i].getNom() << endl;
    }
}



    float calculerSalaire()  {
        float salaireTotal = contrat.getSalaire();

        for (int i = 0; i < primes.size(); i++) {
            salaireTotal += primes[i].getMontant();
        }

        return salaireTotal;
    }
};

class Admin : public Utilisateur {
public:
    Admin(const string& nomUtil, const string& motPasse) : Utilisateur(nomUtil, motPasse) {}
};

class DirecteurRH : public Utilisateur {
public:
    DirecteurRH(const string& nomUtil, const string& motPasse) : Utilisateur(nomUtil, motPasse) {}
};

class Departement {
private:
    string nom;
    vector<Employe*> employes;

public:
    Departement(const string& n) : nom(n) {}

    string getNom() const {
        return nom;
    }

    void ajouterEmploye(Employe* employe) {
        employes.push_back(employe);
        employe->ajouterDepartement(nom);
    }

    void afficherEmployes() const {
        cout << "Employes du departement " << nom << " :" << endl;
        for (int i = 0; i < employes.size(); i++) {
            cout << employes[i]->getNom() << endl;
        }
    }
};

class Service {
private:
    string nom;
    vector<string> employes;

public:
    Service(const string& n) : nom(n) {}
    string getNom() const {
        return nom;
    }

    void ajouterEmploye(const string& employe) {
        employes.push_back(employe);
    }

    void afficherEmployes() const {
        cout << "Employes du service " << nom << " :" << endl;
        for (int i = 0; i < employes.size(); i++) {
            cout << employes[i] << endl;
        }
    }
};

class Formation {
private:
    string nom;
    int dureeEnHeures;
    string dateDeb;
    string dateF;

public:
    Formation(const string& n, int duree,string dd,string df) : nom(n), dureeEnHeures(duree), dateDeb(dd), dateF(df) {}

    void afficherDetails() const {
        cout << "Formation : " << nom << ", Duree : " << dureeEnHeures << " heures" << " ,Date dedebut : " << dateDeb << ",Date de fin : " << dateF << endl;
    }

    string getNom() const {
        return nom;
    }
};

class Ville {
private:
    string nom;
    vector<string> habitants;

public:
    Ville(const string& n) : nom(n) {}

    void ajouterHabitant(const string& habitant) {
        habitants.push_back(habitant);
    }

    void afficherHabitants() const {
        cout << "Habitants de la ville " << nom << " :" << endl;
        for (int i = 0; i < habitants.size(); i++) {
            cout << habitants[i] << endl;
        }
    }

    string getNom() const {
        return nom;
    }
};


class Conge {
private:
    string raison;
    string dateDebut;
    string dateFin;
    vector<Employe> demandeurs;

public:
    Conge(const string& r, string dd, string df) : raison(r), dateDebut(dd), dateFin(df) {}

    void ajouterDemandeur(Employe demandeur) {
        demandeurs.push_back(demandeur);
    }

    void afficherDemandeurs()  {
        cout << "Demandeurs de conge pour " << raison << " :" << endl;
        for (int i = 0; i < demandeurs.size(); i++) {
            cout << demandeurs[i].getNom() << endl;
        }
    }

    string getRaison() const {
        return raison;
    }

};

void Employe::ajouterDepartement(Departement dep) {
        departements.push_back(dep);
    }

void Employe::afficherDepartements()  {
        cout << "Departements de l'employe " << nom << " :" << endl;
        for (int i = 0; i < departements.size(); i++) {
            cout << departements[i].getNom() << endl;
        }
    }
	    
class Entreprise {
private:
    vector<Employe> employes;
    vector<Departement> departements;
    vector<Service> services;
    vector<Formation> formations;
    vector<Contrat> contrats;
    vector<Prime> primes;
    vector<Ville> villes;
    vector<Conge> conges;
    vector<Admin> admins;

public:


    void menuAdmin() {
    	int choix;
    	do{
    	cout << endl<<endl;
    	cout << "***********MENU******************"<<endl;	
        cout << "1: Gerer les employes" << endl;
        cout << "2: Gerer les departements" << endl;
        cout << "3: Gerer les formations" << endl;
        cout << "4: Gerer les services" << endl;
        cout << "5: Gerer les contrat" << endl;
        cout << "6: Gerer les conges" << endl;
        cout << "7: Gerer les primes" << endl;
        cout << "0. Exit" << endl;
        cout << "*****************************"<<endl;
        cout << "Entrez votre choix: "<<endl;
        
        
        cin >> choix;
        switch (choix) {
                case 1:
                    gererEmploye();
                    break;
                case 2:
                    gererDepartement();
                    break;
                case 3:
                    gererFormation();
                    break;
                case 4:
                    gererService();
                    break;
                case 5:
                    gererContrat();
                    break;
                case 6:
                    gererConge();
                    break;
                case 7:
                    gererPrime();
                    break;
                case 0:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choix != 0);
    }
    


    void gererEmploye() {
    int choix;
    do {
    	cout << endl<<endl;
    	cout << "=========================================="<<endl;
        cout << "1: Ajouter un employe" << endl;
        cout << "2: Supprimer un employe" << endl;
        cout << "3: Afficher tous les employes" << endl;
        cout << "4: Retour" << endl;
        cout << "=========================================="<<endl;
        cout << "Entrez votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1:
                ajouterEmploye();
                break;
            case 2:
            	{
                supprimerEmploye();
                break;
            }
            case 3:
                afficherEmployes();
                break;
            case 4:
                cout << "Returning to Admin Menu..." << endl;
                return;  
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choix != 0);
}
        
        
    
    void gererDepartement() {
        int choix;
        do {
            cout << "==========================================" << endl;
            cout << "1: Ajouter un département" << endl;
            cout << "2: Supprimer un département" << endl;
            cout << "3: Afficher tous les départements" << endl;
            cout << "4: Retour" << endl;
            cout << "==========================================" << endl;
            cout << "Entrez votre choix: ";
            cin >> choix;
            switch (choix) {
                case 1:
                    ajouterDepartement();
                    break;
                case 2:
                    supprimerDepartement();
                    break;
                case 3:
                    afficherDepartements();
                    break;
                case 4:
                    cout << "Returning to Admin Menu..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choix != 0);
    }

    void gererFormation() {
         int choix;
        do {
            cout << "==========================================" << endl;
            cout << "1: Ajouter une formation" << endl;
            cout << "2: Supprimer une formation" << endl;
            cout << "3: Afficher toutes les formations disponibles" << endl;
            cout << "4: Retour" << endl;
            cout << "==========================================" << endl;
            cout << "Entrez votre choix: ";
            cin >> choix;
            switch (choix) {
                case 1:
                    ajouterFormation();
                    break;
                case 2:
                    supprimerFormation();
                    break;
                case 3:
                    afficherFormations();
                    break;
                case 4:
                    cout << "Returning to Admin Menu..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choix != 0);
    }

    void gererService() {
         int choix;
        do {
            cout << "==========================================" << endl;
            cout << "1: Ajouter un service" << endl;
            cout << "2: Supprimer un service" << endl;
            cout << "3: Afficher tous les services" << endl;
            cout << "4: Retour" << endl;
            cout << "==========================================" << endl;
            cout << "Entrez votre choix: ";
            cin >> choix;
            switch (choix) {
                case 1:
                    ajouterService();
                    break;
                case 2:
                    supprimerService();
                    break;
                case 3:
                    afficherServices();
                    break;
                case 4:
                    cout << "Returning to Admin Menu..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choix != 0);
    }

    void gererContrat() {
         int choix;
        do {
            cout << "==========================================" << endl;
            cout << "1: Ajouter un contrat d'emploi" << endl;
            cout << "2: Supprimer un contrat d'emploi" << endl;
            cout << "3: Afficher tous les contrats d'emploi" << endl;
            cout << "4: Retour" << endl;
            cout << "==========================================" << endl;
            cout << "Entrez votre choix: ";
            cin >> choix;
            switch (choix) {
                case 1:
                    ajouterContrat();
                    break;
                case 2:
                    supprimerContrat();
                    break;
                case 3:
                    afficherContrats();
                    break;
                case 4:
                    cout << "Returning to Admin Menu..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choix != 0);
    }

    void gererConge() {
       int choix;
        do {
            cout << "==========================================" << endl;
            cout << "1: Enregistrer une demande de congé" << endl;
            cout << "2: Approuver ou rejeter une demande de congé" << endl;
            cout << "3: Afficher les congés accordés" << endl;
            cout << "4: Retour" << endl;
            cout << "==========================================" << endl;
            cout << "Entrez votre choix: ";
            cin >> choix;
            switch (choix) {
                case 1:
                    ajouterConge();
                    break;
                case 2:
                    supprimerConge();
                    break;
                case 3:
                    afficherConges();
                    break;
                case 4:
                    cout << "Returning to Admin Menu..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choix != 0);
    }

    void gererPrime() {
    	int choix;
    	do{
		cout << "==========================================" << endl;
        cout << "Attribuer une prime " << endl;
        cout << "Modifier le montant d'une prime" << endl;
        cout << "Supprimer une prime" << endl;
        cout << "Afficher toutes les primes attribuées" << endl;
        cout << "4: Retour" << endl;
        cout << "==========================================" << endl;
        cout << "Entrez votre choix: ";
        cin >> choix;
            switch (choix) {
                case 1:
                    ajouterPrime();
                    break;
                case 2:
                    supprimerPrime();
                    break;
                case 3:
                    afficherPrimes();
                    break;
                case 4:
                    cout << "Returning to Admin Menu..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choix != 0);
    }

   

    void menuEmploye(Employe E) {
        int choix;
        
    do {
        cout << endl;
        cout << "*********** MENU EMPLOYE ***********" << endl;
        cout << "1. Faire une demande de congé" << endl;
        cout << "2. Voir mon contrat" << endl;
        cout << "3. Voir mes primes" << endl;
        cout << "4. Voir mes départements" << endl;
        cout << "0. Retour" << endl;
        cout << "************************************" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                demandConge(E);
                break;
            case 2:
                afficherContratE(E);
                break;
            case 3:
               afficherPrimesE(E);
                break;
            case 4:
                afficherDepartementE(E);
                break;
            case 0:
                cout << "Retour au menu précédent..." << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 0);
    }

    void Authentification() {
    	bool b=false;
        string mdp, username;
		cout<<"****************AUTHENTIFICATION****************"<<endl;
		
		do {
		cout<<endl;
        cout << "veuillez saisir votre nom d'utilisateur :" << endl;
        cin >> username;
        cout << "veuillez saisir votre mot de passe :" << endl;
        cin >> mdp;

        for (int i = 0; i < admins.size(); i++) {
            if (username == admins[i].getNomUtilisateur() && admins[i].verifierMotDePasse(mdp)) {
            	b=true;
            	menuAdmin();
																								}
    											}
        for (int i=0;i<employes.size();i++){
        	if (username == employes[i].getNomUtilisateur() && employes[i].verifierMotDePasse(mdp)){
        		b=true;
        		menuEmploye(employes[i]);
        																						    }
		}
		if (!b)
		cout<<endl<<" ERREUR : username ou mot de passe incorrecte !"<<endl;
	}while (b==false);
        
        
    											
							}



    void supprimerEmploye() {
    	string nom;
        cout<<"Donner le nom de l'employe :";
        cin>>nom;
    	bool b = false;
    	for(int i=0;i<employes.size();i++){
        if ( nom == employes[i].getNom() ) {
        	 employes.erase(employes.begin() + i);
            cout << "Employee :" << nom << " supprime." <<endl;
            b=true;
        }}
         if (!b) {
            cout << "Nom introuvé" <<endl;
        }
    }

void supprimerFormation() {
    string nom;
    cout<<"Donner le nom de la formation  :";
    cin>>nom;
    bool found = false;
    for (int i = 0; i < formations.size(); ++i) {
        if (nom == formations[i].getNom()) {
            formations.erase(formations.begin() + i);
            cout << "Formation '" << nom << "' supprimée." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Formation introuvable." << endl;
    }
}

void supprimerDepartement() {
    string nom;
    cout<<"Donner le nom du departement  :";
    cin>>nom;
    bool found = false;
    for (int i = 0; i < departements.size(); ++i) {
        if (nom == departements[i].getNom()) {
            departements.erase(departements.begin() + i);
            cout << "Département '" << nom << "' supprimé." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Département introuvable." << endl;
    }
}

void supprimerService() {
    string nom;
    cout<<"Donner le nom du service  :";
    cin>>nom;
    bool found = false;
    for (int i = 0; i < services.size(); ++i) {
        if (nom == services[i].getNom()) {
            services.erase(services.begin() + i);
            cout << "Service '" << nom << "' supprimé." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Service introuvable." << endl;
    }
}

void supprimerContrat() {
    string type;
    cout<<"Donner le type du cintrat  :";
    cin>>type;
    bool found = false;
    for (int i = 0; i < contrats.size(); ++i) {
        if (type == contrats[i].getType()) {
            contrats.erase(contrats.begin() + i);
            cout << "Contrat '" << type << "' supprimé." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contrat introuvable." << endl;
    }
}

void supprimerPrime() {
    string nom;
    cout<<"Donner le nom de la prime  :";
    cin>>nom;
    bool found = false;
    for (int i = 0; i < primes.size(); ++i) {
        if (nom == primes[i].getNom()) {
            primes.erase(primes.begin() + i);
            cout << "Prime '" << nom << "' supprimée." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Prime introuvable." << endl;
    }
}



void supprimerConge() {
	string raison;
    cout<<"Donner la raison du conge  :";
    cin>>raison;
    bool found = false;
    for (int i = 0; i < conges.size(); ++i) {
        if (raison == conges[i].getRaison()) {
            conges.erase(conges.begin() + i);
            cout << "Demande de congé pour '" << raison << "' supprimée." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Raison de congé introuvable." << endl;
    }
}

void ajouterAdmin(Admin A){
	admins.push_back(A);
}

void ajouterEmploye(Employe E){
	employes.push_back(E);
}



void demandConge(Employe E){
	string raison,dd,df;
	cout << "quelle est la raison de votre conge"<<endl;
	cin>>raison;
	cout << "quelle est la date de debut conge"<<endl;
	cin>>dd;
	cout << "quelle est la date de fin de votre conge"<<endl;
	cin>>df;
	Conge C(raison,dd,df);
	C.ajouterDemandeur(E);
}

void ajouterEmploye() {
		string nomUtilisateur, motDePasse, nomEmploye, typeContrat,dateDebut;
        int dureeContrat;
        float salaireContrat;
        cout << "Nom d'utilisateur de l'employe : ";
        cin >> nomUtilisateur;
        cout << "Mot de passe de l'employe : ";
        cin >> motDePasse;
        cin.ignore();
        cout << "Nom de l'employe : ";
        getline(cin, nomEmploye);
        cout << "Type de contrat (ex: CDI) : ";
        cin >> typeContrat;
        cout << "Date de debut du contrat en mois : ";
        cin >> dateDebut;
        cout << "Salaire du contrat : ";
        cin >> salaireContrat;
        Contrat contrat(typeContrat, dateDebut, salaireContrat);
        Employe employe(nomUtilisateur, motDePasse, nomEmploye, contrat);
        employes.push_back(employe);
        cout << "Employe ajoute avec succes !" << endl;
                                     
    }

    void ajouterDepartement() {
    string nom;
    cout << "Nom du département : ";
    cin >> nom;
    Departement departement(nom);
    departements.push_back(departement);
    cout << "Département ajouté avec succès !" << endl;
}

void ajouterService() {
    string nom;
    cout << "Nom du service : ";
    cin >> nom;
    Service service(nom);
    services.push_back(service);
    cout << "Service ajouté avec succès !" << endl;
}

void ajouterFormation() {
    string nom;
    int duree;
    string dd,df;
    cout << "Nom de la formation : ";
    cin >> nom;
    cout << "Durée de la formation en heures : ";
    cin >> duree;
    cin.ignore();
    cout << "Date de debut de la formation : ";
    cin >> dd;
    cout << "Date de fin de la formation : ";
    cin >> df;
    Formation formation(nom, duree,dd,df);
    formations.push_back(formation);
    cout << "Formation ajoutée avec succès !" << endl;
}

void ajouterContrat() {
    string type;
    string dateDebut;
    float salaire;
    cout << "Type de contrat : ";
    cin >> type;
    cout << "Date de debut du contrat : ";
    cin >> dateDebut;
    Contrat contrat(type, dateDebut, salaire);
    contrats.push_back(contrat);
    cout << "Contrat ajouté avec succès !" << endl;
}

void ajouterPrime() {
    string nom;
    float montant;
    cout << "Nom de la prime : ";
    cin >> nom;
    cout << "Montant de la prime : ";
    cin >> montant;
    Prime prime(nom, montant);
    primes.push_back(prime);
    cout << "Prime ajoutée avec succès !" << endl;
}


    void ajouterVille(const Ville& ville) {
        villes.push_back(ville);
    }



    void ajouterConge() {
    string raison,dd,df;
    cout << "Raison du congé : ";
    cin >> raison;
    cout << "Date de debut du congé : ";
    cin >> dd;
    cout << "Date de fin du congé : ";
    cin >> df;
    Conge conge(raison,dd,df);
    conges.push_back(conge);
    cout << "Congé ajouté avec succès !" << endl;
}


    void afficherEmployes()  {
        cout << "Liste des employes :" << endl;
        for (int i = 0; i < employes.size(); i++) {
            cout << employes[i].getNom() << endl;
        }
    }

    void afficherDepartements() const {
        cout << "Liste des departements :" << endl;
        for (int i = 0; i < departements.size(); i++) {
            cout << departements[i].getNom() << endl;
        }
    }

    void afficherServices() const {
        cout << "Liste des services :" << endl;
        for (int i = 0; i < services.size(); i++) {
            cout << services[i].getNom() << endl;
        }
    }


    void afficherFormations() {
        cout << "Liste des formations :" << endl;
        for (int i = 0; i < formations.size(); i++) {
            cout << formations[i].getNom() << endl;
        }
    }

    void afficherContrats() {
        cout << "Liste des contrats :" << endl;
        for (int i = 0; i < contrats.size(); i++) {
            cout << contrats[i].getType() << endl;
        }
    }

    void afficherPrimes() {
        cout << "Liste des primes :" << endl;
        for (int i = 0; i < primes.size(); i++) {
            cout << primes[i].getNom() << endl;
        }
    }

    void afficherVilles() {
        cout << "Liste des villes :" << endl;
        for (int i = 0; i < villes.size(); i++) {
            cout << villes[i].getNom() << endl;
        }
    }



    void afficherConges() {
        cout << "Liste des congÃ©s :" << endl;
        for (int i = 0; i < conges.size(); i++) {
            cout << conges[i].getRaison() << endl;
        }
    }
    
    void afficherDepartementE(Employe E){
    	E.afficherDepartements();
	}
	void afficherPrimesE(Employe E){
		E.afficherPrimes();
	}
	void afficherContratE(Employe E){
		E.afficherContrat();
	}

};

int main() {

    Entreprise entreprise;
    Contrat C1("Contrat ", "7/8/2024", 2500.0);

    Employe E1("username", "123456", "Adam", C1);
    Employe E2("username", "123456", "hamid", C1);
    Employe E3("username", "123456", "ahmed", C1);
    Employe E4("username", "123456", "mehdi", C1);
    Employe E5("username", "123456", "rachid", C1);
    
    entreprise.ajouterEmploye(E1);
    entreprise.ajouterEmploye(E2);
    entreprise.ajouterEmploye(E3);
    entreprise.ajouterEmploye(E4);
    entreprise.ajouterEmploye(E5);
    
    
    
    
	Admin A("adam","adam123");
	entreprise.ajouterAdmin(A);
    

    entreprise.Authentification();

    return 0;
}

