class BPAI{
	public:char cnes[100];
	public:char cmpt[100];
	public:char prof_cns[100];
	public:char cbo[100];
	public:char atnd_data[100];
	public:char fl[100];
	public:char seq[100];
	public:char proc[100];
	public:char pac_cns[100];
	public:char sexo[100];
	public:char ibge[100];
	public:char cid[100];
	public:char idade[100];
	public:char qtdd[100];
	public:char ca[100];		//Caracter de atendimento
	public:char nae[100];		//Numero de autorização do estabelecimento
	public:char orgn[100];		//Origem das informações
	public:char pac_name[100];
	public:char nsc_data[100];
	public:char raca[100];
	public:char etnia[100];
	public:char nac[100];		//Nacionalidade
	public:char srv_code[100];
	public:char class_code[100];
	public:char cse[100];			//Código da sequencia da equipe
	public:char cae[100];			//Código da área da equipe
	public:char cnpj[100];
	public:char cep[100];
	public:char log_type[100];
	public:char log[1000];			//Rua
	public:char complemento[1000];
	public:char ln[1000];			//n° de casa
	public:char bairro[1000];
	public:char tel[100];
	public:char email[100];
	public:char ine[100];			//Identificação nacional da equipe
	char raw_line[5000];
	
	public:unsigned long long int id;	//Identificador da linha: serve pra mesmo após várias alterações a linha inconsistente ainda ser rastreável
	
	private:char *getTblCol(char *str, int col){
		int p = 0;
		int x = 0;
		
		while(p < col && str[x] != 0){
			if(str[x] == '\t'){
				++p;
			}
			++x;
		}
		
		char drop[1000];
		int y = 0;
		
		while(str[x] != '\t' && str[x] != 0 && str[x] != '\n' && str[x] != '\r'){
			drop[y] = str[x];
			++x;
			++y;
		}
		drop[y] = 0;
		
		return drop;
	}
	
	private:char *addLeftZ(char *str, int max_len){
		char drop[1000];
		drop[0] = 0;
		int y = 0;
		
		while(strlen(drop) + strlen(str) < max_len){
			strcat(drop, "0");
		}
		
		strcat(drop, str);
		
		return drop;
	}
	
	private:char *fillUntil(char *str, int max_len){
		char drop[1000];
		strcpy(drop, str);
		
		while(strlen(drop) < max_len){
			strcat(drop, " ");
		}
		
		return drop;
	}
	
	public:BPAI(char *line, bool bpa){
		strcpy(raw_line, line);
		if(raw_line[strlen(raw_line) - 1] == '\n' || raw_line[strlen(raw_line) - 1] == '\r'){
			raw_line[strlen(raw_line) - 1] = 0;
		}
		
		if(bpa){
			strcpy(cnes, String(line).substringUtf8(2, 9));
			strcpy(cmpt, String(line).substringUtf8(9, 15));
			strcpy(prof_cns, String(line).substringUtf8(15, 30));
			strcpy(cbo, String(line).substringUtf8(30, 36));
			strcpy(atnd_data, String(line).substringUtf8(36, 44));
			strcpy(fl, String(line).substringUtf8(44, 47));
			strcpy(seq, String(line).substringUtf8(47, 49));
			strcpy(proc, String(line).substringUtf8(49, 59));
			strcpy(pac_cns, String(line).substringUtf8(59, 74));
			strcpy(sexo, String(line).substringUtf8(74, 75));
			strcpy(ibge, String(line).substringUtf8(75, 81));
			strcpy(cid, String(line).substringUtf8(81, 85));
			strcpy(idade, String(line).substringUtf8(85, 88));
			strcpy(qtdd, String(line).substringUtf8(88, 94));
			strcpy(ca, String(line).substringUtf8(94, 96));
			strcpy(nae, String(line).substringUtf8(96, 109));
			strcpy(orgn, String(line).substringUtf8(109, 112));
			strcpy(pac_name, String(line).substringUtf8(112, 142));
			strcpy(nsc_data, String(line).substringUtf8(142, 150));
			strcpy(raca, String(line).substringUtf8(150, 152));
			strcpy(etnia, String(line).substringUtf8(152, 156));
			strcpy(nac, String(line).substringUtf8(156, 159));
			strcpy(srv_code, String(line).substringUtf8(159, 162));
			strcpy(class_code, String(line).substringUtf8(162, 165));
			strcpy(cse, String(line).substringUtf8(165, 173));
			strcpy(cae, String(line).substringUtf8(173, 177));
			strcpy(cnpj, String(line).substringUtf8(177, 191));
			strcpy(cep, String(line).substringUtf8(191, 199));
			strcpy(log_type, String(line).substringUtf8(199, 202));
			strcpy(log, String(line).substringUtf8(202, 232));
			strcpy(complemento, String(line).substringUtf8(232, 242));
			strcpy(ln, String(line).substringUtf8(242, 247));
			strcpy(bairro, String(line).substringUtf8(247, 277));
			strcpy(tel, String(line).substringUtf8(277, 288));
			strcpy(email, String(line).substringUtf8(288, 328));
			strcpy(ine, String(line).substringUtf8(328, 338));
		}
		else{
			//03	0944394	202210	
			//c3 > 706005822898940	225320	20221028	001	01	
			//c8 > 0205020046	898050077562331	M	320060	    	059	000001	01	             	EXT	PAULO CESAR LEONI             	19630504	03	    	010	121	002	        	    	00000000000000	29190010	081	RODOVIA BR 101                	          	000SN	GUARANA                       	           	                                        	
			strcpy(cnes, getTblCol(line, 1));
			strcpy(cnes, addLeftZ(cnes, 7));
			
			strcpy(cmpt, getTblCol(line, 2));
			strcpy(prof_cns, getTblCol(line, 3));
			strcpy(cbo, getTblCol(line, 4));
			strcpy(atnd_data, getTblCol(line, 5));
			
			strcpy(fl, getTblCol(line, 6));
			strcpy(fl, addLeftZ(fl, 3));
			
			strcpy(seq, getTblCol(line, 7));
			strcpy(seq, addLeftZ(seq, 2));
			
			strcpy(proc, getTblCol(line, 8));
			strcpy(proc, addLeftZ(proc, 10));
			
			strcpy(pac_cns, getTblCol(line, 9));
			strcpy(sexo, getTblCol(line, 10));
			strcpy(ibge, getTblCol(line, 11));
			
			strcpy(cid, getTblCol(line, 12));
			strcpy(cid, fillUntil(cid, 4));
			
			strcpy(idade, getTblCol(line, 13));
			strcpy(idade, addLeftZ(idade, 3));
			
			strcpy(qtdd, getTblCol(line, 14));
			strcpy(qtdd, addLeftZ(qtdd, 6));
			
			strcpy(ca, getTblCol(line, 15));
			strcpy(ca, addLeftZ(ca, 2));
			
			strcpy(nae, getTblCol(line, 16));
			if(nae[0] == ' '){
				strcpy(nae, fillUntil(nae, 13));
			}
			else{
				strcpy(nae, addLeftZ(nae, 13));
			}
			
			strcpy(orgn, getTblCol(line, 17));
			
			strcpy(pac_name, getTblCol(line, 18));
			strcpy(pac_name, fillUntil(pac_name, 30));
			
			strcpy(nsc_data, getTblCol(line, 19));
			
			strcpy(raca, getTblCol(line, 20));
			strcpy(raca, addLeftZ(raca, 2));
			
			strcpy(etnia, getTblCol(line, 21));
			if(etnia[0] != ' '){
				strcpy(etnia, addLeftZ(etnia, 4));
			}
			else{
				strcpy(etnia, fillUntil(etnia, 4));
			}
			
			strcpy(nac, getTblCol(line, 22));
			strcpy(nac, addLeftZ(nac, 3));
			
			strcpy(srv_code, getTblCol(line, 23));
			if(srv_code[0] != ' '){
				strcpy(srv_code, addLeftZ(srv_code, 3));
			}
			
			strcpy(class_code, getTblCol(line, 24));
			if(class_code[0] != ' '){
				strcpy(class_code, addLeftZ(class_code, 3));
			}
			
			strcpy(cse, getTblCol(line, 25));
			if(cse[0] != ' '){
				strcpy(cse, addLeftZ(cse, 8));
			}
			
			strcpy(cae, getTblCol(line, 26));
			if(cae[0] != ' '){
				strcpy(cae, addLeftZ(cae, 4));
			}
			else{
				strcpy(cae, fillUntil(cae, 4));
			}
			
			
			strcpy(cnpj, getTblCol(line, 27));
			if(cnpj[0] != ' '){
				strcpy(cnpj, addLeftZ(cnpj, 14));
			}
			else{
				strcpy(cnpj, fillUntil(cnpj, 14));
			}
			
			strcpy(cep, getTblCol(line, 28));
			
			strcpy(log_type, getTblCol(line, 29));
			strcpy(log_type, addLeftZ(log_type, 3));
			
			
			strcpy(log, getTblCol(line, 30));
			strcpy(log, fillUntil(log, 30));
			
			strcpy(complemento, getTblCol(line, 31));
			strcpy(complemento, fillUntil(complemento, 10));
			
			strcpy(ln, getTblCol(line, 32));
			strcpy(ln, fillUntil(ln, 5));
			
			strcpy(bairro, getTblCol(line, 33));
			strcpy(bairro, fillUntil(bairro, 30));
			
			strcpy(tel, getTblCol(line, 34));
			strcpy(tel, fillUntil(tel, 11));
			
			strcpy(email, getTblCol(line, 35));
			strcpy(email, fillUntil(email, 40));
			
			strcpy(ine, getTblCol(line, 36));
			if(ine[0] != ' ' && ine[0] != 0){
				strcpy(ine, addLeftZ(ine, 10));
			}
			else{
				strcpy(ine, fillUntil(ine, 10));
			}
		}
		
		
	}
	
	public:char *getLine(){
		char drop[30000];
		
		strcpy(drop, "03");
		strcat(drop, cnes);
		strcat(drop, cmpt);
		strcat(drop, prof_cns);
		strcat(drop, cbo);
		strcat(drop, atnd_data);
		strcat(drop, fl);
		strcat(drop, seq);
		strcat(drop, proc);
		strcat(drop, pac_cns);
		strcat(drop, sexo);
		strcat(drop, ibge);
		strcat(drop, cid);
		strcat(drop, idade);
		strcat(drop, qtdd);
		strcat(drop, ca);
		strcat(drop, nae);
		strcat(drop, orgn);
		strcat(drop, pac_name);
		strcat(drop, nsc_data);
		strcat(drop, raca);
		strcat(drop, etnia);
		strcat(drop, nac);
		strcat(drop, srv_code);
		strcat(drop, class_code);
		strcat(drop, cse);
		strcat(drop, cae);
		strcat(drop, cnpj);
		strcat(drop, cep);
		strcat(drop, log_type);
		strcat(drop, log);
		strcat(drop, complemento);
		strcat(drop, ln);
		strcat(drop, bairro);
		strcat(drop, tel);
		strcat(drop, email);
		strcat(drop, ine);
		
		while(drop[strlen(drop) - 1] == '\n'){
			drop[strlen(drop) - 1] = 0;
		}
		
		return drop;
	}
	
	public:char *get2ExcelLine(){
		char drop[30000];
		
		strcpy(drop, "03");
		strcat(drop, "\t");
		strcat(drop, cnes);
		strcat(drop, "\t");
		strcat(drop, cmpt);
		strcat(drop, "\t");
		strcat(drop, prof_cns);
		strcat(drop, "\t");
		strcat(drop, cbo);
		strcat(drop, "\t");
		strcat(drop, atnd_data);
		strcat(drop, "\t");
		strcat(drop, fl);
		strcat(drop, "\t");
		strcat(drop, seq);
		strcat(drop, "\t");
		strcat(drop, proc);
		strcat(drop, "\t");
		strcat(drop, pac_cns);
		strcat(drop, "\t");
		strcat(drop, sexo);
		strcat(drop, "\t");
		strcat(drop, ibge);
		strcat(drop, "\t");
		strcat(drop, cid);
		strcat(drop, "\t");
		strcat(drop, idade);
		strcat(drop, "\t");
		strcat(drop, qtdd);
		strcat(drop, "\t");
		strcat(drop, ca);
		strcat(drop, "\t");
		strcat(drop, nae);
		strcat(drop, "\t");
		strcat(drop, orgn);
		strcat(drop, "\t");
		strcat(drop, pac_name);
		strcat(drop, "\t");
		strcat(drop, nsc_data);
		strcat(drop, "\t");
		strcat(drop, raca);
		strcat(drop, "\t");
		strcat(drop, etnia);
		strcat(drop, "\t");
		strcat(drop, nac);
		strcat(drop, "\t");
		strcat(drop, srv_code);
		strcat(drop, "\t");
		strcat(drop, class_code);
		strcat(drop, "\t");
		strcat(drop, cse);
		strcat(drop, "\t");
		strcat(drop, cae);
		strcat(drop, "\t");
		strcat(drop, cnpj);
		strcat(drop, "\t");
		strcat(drop, cep);
		strcat(drop, "\t");
		strcat(drop, log_type);
		strcat(drop, "\t");
		strcat(drop, log);
		strcat(drop, "\t");
		strcat(drop, complemento);
		strcat(drop, "\t");
		strcat(drop, ln);
		strcat(drop, "\t");
		strcat(drop, bairro);
		strcat(drop, "\t");
		strcat(drop, tel);
		strcat(drop, "\t");
		strcat(drop, email);
		strcat(drop, "\t");
		strcat(drop, ine);
		
		while(drop[strlen(drop) - 1] == '\n'){
			drop[strlen(drop) - 1] = 0;
		}
		
		
		return drop;
	}
};


class BPAIList{
	public:int lsz = 0;
	public:BPAI *list[65000];
	public:char mainCmpt[100];
	
	public: void add(BPAI *bpai){
		if(lsz == 65000){
			int x = 1;
		
			while(x < lsz){
				list[x - 1] = list[x];
				list[x] = NULL;
				++x;
			}
			
			--lsz;
		}
		list[lsz] = (BPAI*)malloc(sizeof(BPAI));
		++lsz;
		//strcpy(list[lsz - 1], str);
		list[lsz - 1] = bpai;
	}
	
	public: void remove(int i){
		int x = i + 1;
		
		while(x < lsz){
			list[x - 1] = list[x];
			list[x] = NULL;
			++x;
		}
		
		--lsz;
	}
	
	//Verifica se str se trata de uma linha obtida em um arquivo BPA
	private:bool isABPAFile(char *str){
		for(int i = 0; str[i] != 0; i++){
			if(str[i] == '\t'){
				return false;
			}
		}
		return true;
	}
	
	private:char *getTblCol(char *str, int col){
		int p = 0;
		int x = 0;
		
		while(p < col && str[x] != 0){
			if(str[x] == '\t'){
				++p;
			}
			++x;
		}
		
		char drop[1000];
		int y = 0;
		
		while(str[x] != '\t' && str[x] != 0 && str[x] != '\n' && str[x] != '\r'){
			drop[y] = str[x];
			++x;
			++y;
		}
		drop[y] = 0;
		
		return drop;
	}
	
	public:bool loadOfFile(char *filename){
		FILE *f = fopen(filename, "r");
		if(f == NULL){
			return false;
		}
		
		fseek(f, 0, SEEK_END);
		unsigned long long int fsz = ftell(f);
		fseek(f, 0, SEEK_SET);
		char line[5000];
		fgets(line, 5000, f);
		
		bool isBPA = isABPAFile(line);
		
		if(isBPA){
			strcpy(mainCmpt, String(line).substring(7, 13));
		
			FILE *f2 = fopen("header.cfg", "w");
			fprintf(f2, "%s\n", String(line).substring(29));
			fclose(f2);
		}
		else{
			fgets(line, 5000, f);
			strcpy(mainCmpt, getTblCol(line, 2));
			fseek(f, 0, SEEK_SET);
			fgets(line, 5000, f);
		}
		
		while(ftell(f) < fsz){
			fgets(line, 5000, f);
			
			if(isBPA && line[0] == '0' && line[1] == '3'){
				add(new BPAI(line, isBPA));
			}
			else if(!isBPA){
				add(new BPAI(line, isBPA));
			}
		}
		
		fclose(f);
		
		return true;
	}
	
	
	public:unsigned long long int getProcCodeSum(){
		unsigned long long int drop = 0;
		
		for(int i = 0; i < lsz; i++){
			drop += strtoull(list[i]->proc, NULL, 10);
		}
		
		return drop;
	}
	
	public:unsigned long long int getProcQtddSum(){
		unsigned long long int drop = 0;
		
		for(int i = 0; i < lsz; i++){
			drop += strtoull(list[i]->qtdd, NULL, 10);
		}
		
		return drop;
	}
	
	public: int getLoadedFls(){
		int fls = 0;
		
		for(int i = 0; i < lsz; i++){
			
			if(atoi(list[i]->seq) == 1){
				++fls;
			}
		}
		
		return fls;
	}
	
	public:BPAIList *sublist(long start, long end){
		BPAIList *drop = new BPAIList();
		
		for(long i = start; i < end; i++){
			drop->add(list[i]);
		}
		
		return drop;
	}
	
	//Igual strcmp porem com performance superior
	private:bool equals(char *str1, char *str2){
		
		for(int i = 0; str1[i] != 0 || str2[i] != 0; i++){
			
			if(str1[i] != str2[i]){
				return false;
			}
		}
		
		return true;
	}
	
	//Retorna a lista atual porem sem os registros referentes a competencia especificada
	public:BPAIList *woCmpt(char *cmpt){
		BPAIList *drop = new BPAIList();
		
		for(long i = 0; i < lsz; i++){
			
			if(!equals(list[i]->cmpt, cmpt)){
				drop->add(list[i]);
			}
		}
		
		return drop;
	}
	
	public:BPAIList *onlyCmpt(char *cmpt){
		BPAIList *drop = new BPAIList();
		strcpy(drop->mainCmpt, mainCmpt);
		
		for(long i = 0; i < lsz; i++){
			
			if(equals(list[i]->cmpt, cmpt)){
				drop->add(list[i]);
			}
		}
		
		return drop;
	}
	
	public:char *getLowerCmpt(){
		char drop[100];
		
		ArrayList<char*> low_cmpt_list;
		if(lsz > 0){
			low_cmpt_list.add(list[0]->cmpt);
		}
		else{
			strcpy(drop, "NULL");
			return drop;
		}
		
		for(unsigned long long int i = 1; i < lsz; i++){
			
			if(!low_cmpt_list.contains(list[i]->cmpt)){
				low_cmpt_list.add(list[i]->cmpt);
			}
		}
		
		low_cmpt_list.sort();
		
		strcpy(drop, low_cmpt_list.get(0));
		return drop;
	}
	
	public:char *getHigerCmpt(){
		char drop[100];
		
		ArrayList<char*> high_cmpt_list;
		if(lsz > 0){
			high_cmpt_list.add(list[0]->cmpt);
		}
		else{
			strcpy(drop, "NULL");
			return drop;
		}
		
		for(unsigned long long int i = 1; i < lsz; i++){
			unsigned long long int x = 0;
			bool cnts = false;
			
			while(!cnts && x < high_cmpt_list.size()){
				
				if(equals(list[i]->cmpt, high_cmpt_list.get(x))){
					cnts = true;
				}
				
				++x;
			}
			
			if(!cnts){
				high_cmpt_list.add(list[i]->cmpt);
			}
		}
		
		high_cmpt_list.sort();
		
		
		char *drop2 = high_cmpt_list.get(high_cmpt_list.size() - 1);
		return drop2;
	}
	
	public:char *getNextCmpt(char *ccmpt){
		int y = atoi(String(ccmpt).substring(0, 4));
		int m = atoi(String(ccmpt).substring(4, 6));
		
		
		if(m < 12){
			++m;
		}
		else{
			++y;
			m = 1;
		}
		
		char drop[100];
		
		if(m < 10){
			sprintf(drop, "%d0%d", y, m);
		}
		else{
			sprintf(drop, "%d%d", y, m);
		}
		
		
		return drop;
	}
	
	private:char *getHeaderText(){
		char drop[1000];
		FILE *f = fopen("header.cfg", "r");
		fgets(drop, 1000, f);
		fclose(f);
		
		while(drop[strlen(drop) - 1] == '\n' || drop[strlen(drop) - 1] == '\r'){
			drop[strlen(drop) - 1] = 0;
		}
		
		return drop;
	}
	
	public:void dropFormated2Excel(char *filename){
		FILE *f = fopen(filename, "wb");
		char c_line[5000];
		char tab_header[5000];
		
		
		strcpy(tab_header, "Tipo de registro\t");
		strcat(tab_header, "CNES\t");
		strcat(tab_header, "Competencia\t");
		strcat(tab_header, "CNS do prof.\t");
		strcat(tab_header, "CBO\t");
		strcat(tab_header, "Data do atendimento\t");
		strcat(tab_header, "Folha\t");
		strcat(tab_header, "Sequencia\t");
		strcat(tab_header, "Procedimento\t");
		strcat(tab_header, "CNS do pac.\t");
		strcat(tab_header, "Sexo\t");
		strcat(tab_header, "IBGE\t");
		strcat(tab_header, "CID\t");
		strcat(tab_header, "Idade\t");
		strcat(tab_header, "Quantidade\t");
		strcat(tab_header, "Carac. do atend.\t");
		strcat(tab_header, "N. da aut. do estab.\t");
		strcat(tab_header, "Origem\t");
		strcat(tab_header, "Nome\t");
		strcat(tab_header, "Data de nasc.\t");
		strcat(tab_header, "Raça\t");
		strcat(tab_header, "Etnia\t");
		strcat(tab_header, "Nacionalidade\t");
		strcat(tab_header, "Cód. do serv.\t");
		strcat(tab_header, "Cód. da class.\t");
		strcat(tab_header, "Cód. da seq. da equipe\t");
		strcat(tab_header, "Cód. area da equipe\t");
		strcat(tab_header, "CNPJ\t");
		strcat(tab_header, "CEP\t");
		strcat(tab_header, "Tipo de logradouro\t");
		strcat(tab_header, "Endereço\t");
		strcat(tab_header, "Complemento\t");
		strcat(tab_header, "Casa\t");
		strcat(tab_header, "Bairro\t");
		strcat(tab_header, "Telefone\t");
		strcat(tab_header, "Email\t");
		strcat(tab_header, "INE");
		fprintf(f, "%s\r\n", tab_header);
		
		for(int i = 0; i < lsz; i++){
			strcpy(c_line, list[i]->get2ExcelLine());
			fprintf(f, "%s\r\n", c_line);
		}
		
		fclose(f);
	}
};

class BPAC{
	public:char cnes[100];
	public:char cmpt[100];
	public:char cbo[100];
	public:char fl[100];
	public:char seq[100];
	public:char proc[100];
	public:char idade[100];
	public:char qtdd[100];
	public:char orgn[100];
	
	private:char *getTblCol(char *str, int col){
		int p = 0;
		int x = 0;
		
		while(p < col && str[x] != 0){
			if(str[x] == '\t'){
				++p;
			}
			++x;
		}
		
		char drop[1000];
		int y = 0;
		
		while(str[x] != '\t' && str[x] != 0 && str[x] != '\n' && str[x] != '\r'){
			drop[y] = str[x];
			++x;
			++y;
		}
		drop[y] = 0;
		
		return drop;
	}
	
	private:char *addLeftZ(char *str, int max_len){
		char drop[1000];
		drop[0] = 0;
		int y = 0;
		
		while(strlen(drop) + strlen(str) < max_len){
			strcat(drop, "0");
		}
		
		strcat(drop, str);
		
		return drop;
	}
	
	private:char *fillUntil(char *str, int max_len){
		char drop[1000];
		strcpy(drop, str);
		
		while(strlen(drop) < max_len){
			strcat(drop, " ");
		}
		
		return drop;
	}
	
	public:BPAC(char *line, bool bpa){
		
		if(bpa){
			strcpy(cnes, String(line).substringUtf8(2, 9));
			strcpy(cmpt, String(line).substringUtf8(9, 15));
			strcpy(cbo, String(line).substringUtf8(15, 21));
			strcpy(fl, String(line).substringUtf8(21, 24));
			strcpy(seq, String(line).substringUtf8(24, 26));
			strcpy(proc, String(line).substringUtf8(26, 36));
			strcpy(idade, String(line).substringUtf8(36, 39));
			strcpy(qtdd, String(line).substringUtf8(39, 45));
			strcpy(orgn, String(line).substringUtf8(45, 48));
		}
		else{
			strcpy(cnes, getTblCol(line, 1));
			strcpy(cnes, addLeftZ(cnes, 7));
			
			strcpy(cmpt, getTblCol(line, 2));
			strcpy(cbo, getTblCol(line, 3));
			
			strcpy(fl, getTblCol(line, 4));
			strcpy(fl, addLeftZ(fl, 3));
			
			strcpy(seq, getTblCol(line, 5));
			strcpy(seq, addLeftZ(seq, 2));
			
			strcpy(proc, getTblCol(line, 6));
			strcpy(proc, addLeftZ(proc, 10));
			
			strcpy(idade, getTblCol(line, 7));
			strcpy(idade, addLeftZ(idade, 3));
			
			strcpy(qtdd, getTblCol(line, 8));
			strcpy(qtdd, addLeftZ(qtdd, 6));
			
			strcpy(orgn, getTblCol(line, 9));
		}
		
	}
	
	public:char *getLine(){
		char drop[5000];
		
		
		strcpy(drop, "02");
		strcat(drop, cnes);
		strcat(drop, cmpt);
		strcat(drop, cbo);
		strcat(drop, fl);
		strcat(drop, seq);
		strcat(drop, proc);
		strcat(drop, idade);
		strcat(drop, qtdd);
		strcat(drop, orgn);
		
		return drop;
	}
	
	public:char *get2ExcelLine(){
		char drop[5000];
		
		strcpy(drop, "02");
		strcat(drop, "\t");
		strcat(drop, cnes);
		strcat(drop, "\t");
		strcat(drop, cmpt);
		strcat(drop, "\t");
		strcat(drop, cbo);
		strcat(drop, "\t");
		strcat(drop, fl);
		strcat(drop, "\t");
		strcat(drop, seq);
		strcat(drop, "\t");
		strcat(drop, proc);
		strcat(drop, "\t");
		strcat(drop, idade);
		strcat(drop, "\t");
		strcat(drop, qtdd);
		strcat(drop, "\t");
		strcat(drop, orgn);
		
		return drop;
	}
};


class BPACList{
	public:int lsz = 0;
	public:BPAC *list[65000];
	public:char mainCmpt[100];
	
	
	public:void add(BPAC *bpac){
		if(lsz == 65000){
			int x = 1;
		
			while(x < lsz){
				list[x - 1] = list[x];
				list[x] = NULL;
				++x;
			}
			
			--lsz;
		}
		list[lsz] = (BPAC*)malloc(sizeof(BPAC));
		list[lsz] = bpac;
		++lsz;
	}
	
	
	//Verifica se str se trata de uma linha obtida em um arquivo BPA
	private:bool isABPAFile(char *str){
		for(int i = 0; str[i] != 0; i++){
			if(str[i] == '\t'){
				return false;
			}
		}
		return true;
	}
	
	private:char *getTblCol(char *str, int col){
		int p = 0;
		int x = 0;
		
		while(p < col && str[x] != 0){
			if(str[x] == '\t'){
				++p;
			}
			++x;
		}
		
		char drop[1000];
		int y = 0;
		
		while(str[x] != '\t' && str[x] != 0 && str[x] != '\n' && str[x] != '\r'){
			drop[y] = str[x];
			++x;
			++y;
		}
		drop[y] = 0;
		
		return drop;
	}
	
	
	public:bool loadOfFile(char *filename){
		FILE *f = fopen(filename, "r");
		if(f == NULL){
			return false;
		}
		
		fseek(f, 0, SEEK_END);
		unsigned long long int fsz = ftell(f);
		fseek(f, 0, SEEK_SET);
		char line[5000];
		fgets(line, 5000, f);
		
		bool isBPA = isABPAFile(line);
		
		if(isBPA){
			strcpy(mainCmpt, String(line).substring(7, 13));
		
			FILE *f2 = fopen("header.cfg", "w");
			fprintf(f2, "%s\n", String(line).substring(29));
			fclose(f2);
		}
		else{
			fgets(line, 5000, f);
			strcpy(mainCmpt, getTblCol(line, 2));
			fseek(f, 0, SEEK_SET);
			fgets(line, 5000, f);
		}
		
		while(ftell(f) < fsz){
			fgets(line, 5000, f);
			
			if(isBPA && line[0] == '0' && line[1] == '2'){
				add(new BPAC(line, isBPA));
			}
			else if(!isBPA){
				add(new BPAC(line, isBPA));
			}
		}
		
		fclose(f);
		
		return true;
	}
	
	public:unsigned long long int getProcCodeSum(){
		unsigned long long int drop = 0;
		
		for(int i = 0; i < lsz; i++){
			drop += strtoull(list[i]->proc, NULL, 10);
		}
		
		return drop;
	}
	
	public:unsigned long long int getProcQtddSum(){
		unsigned long long int drop = 0;
		
		for(int i = 0; i < lsz; i++){
			drop += strtoull(list[i]->qtdd, NULL, 10);
		}
		
		return drop;
	}
	
	public:int getLoadedFls(){
		int fls = 0;
		
		for(int i = 0; i < lsz; i++){
			
			if(atoi(list[i]->seq) == 1){
				++fls;
			}
			
		}
		
		return fls;
	}
	
	//Igual strcmp porem com performance superior
	private:bool equals(char *str1, char *str2){
		
		for(int i = 0; str1[i] != 0 || str2[i] != 0; i++){
			
			if(str1[i] != str2[i]){
				return false;
			}
		}
		
		return true;
	}
	
	//Retorna a lista atual porem sem os registros referentes a competencia especificada
	public:BPACList *woCmpt(char *cmpt){
		BPACList *drop = new BPACList();
		
		for(long i = 0; i < lsz; i++){
			
			if(!equals(list[i]->cmpt, cmpt)){
				drop->add(list[i]);
			}
		}
		
		return drop;
	}
	
	public:BPACList *onlyCmpt(char *cmpt){
		BPACList *drop = new BPACList();
		strcpy(drop->mainCmpt, cmpt);
		
		for(long i = 0; i < lsz; i++){
			
			if(equals(list[i]->cmpt, cmpt)){
				drop->add(list[i]);
			}
		}
		
		return drop;
	}
	
	
	public:char *getLowerCmpt(){
		char drop[100];
		
		ArrayList<char*> low_cmpt_list;
		if(lsz > 0){
			low_cmpt_list.add(list[0]->cmpt);
		}
		else{
			strcpy(drop, "NULL");
			return drop;
		}
		
		for(unsigned long long int i = 1; i < lsz; i++){
			
			if(!low_cmpt_list.contains(list[i]->cmpt)){
				low_cmpt_list.add(list[i]->cmpt);
			}
		}
		
		low_cmpt_list.sort();
		
		strcpy(drop, low_cmpt_list.get(0));
		return drop;
	}
	
	public:char *getHigerCmpt(){
		char drop[100];
		
		ArrayList<char*> high_cmpt_list;
		if(lsz > 0){
			high_cmpt_list.add(list[0]->cmpt);
		}
		else{
			strcpy(drop, "NULL");
			return drop;
		}
		
		for(unsigned long long int i = 1; i < lsz; i++){
			unsigned long long int x = 0;
			bool cnts = false;
			
			while(!cnts && x < high_cmpt_list.size()){
				
				if(equals(list[i]->cmpt, high_cmpt_list.get(x))){
					cnts = true;
				}
				
				++x;
			}
			
			if(!cnts){
				high_cmpt_list.add(list[i]->cmpt);
			}
		}
		
		high_cmpt_list.sort();
		
		char *drop2 = high_cmpt_list.get(high_cmpt_list.size() - 1);
		return drop2;
	}
	
	public:char *getNextCmpt(char *ccmpt){
		int y = atoi(String(ccmpt).substring(0, 4));
		int m = atoi(String(ccmpt).substring(4, 6));
		
		if(m < 12){
			++m;
		}
		else{
			++y;
			m = 1;
		}
		
		char drop[100];
		
		if(m < 10){
			sprintf(drop, "%d0%d", y, m);
		}
		else{
			sprintf(drop, "%d%d", y, m);
		}
		
		
		return drop;
	}
	
	public:int getNextFl2CNES(char *cnes){
		int fl = 1;
		int seq = 1;
		
		for(int i = 0; i < lsz; i++){
			
			if(strcmp(list[i]->cnes, cnes) == 0){
				int cfl = atoi(list[i]->fl);
				int cseq = atoi(list[i]->seq);
				
				if(cfl > fl || (cfl == fl && cseq > seq)){
					fl = cfl;
					seq = cseq;
				}
			}
		}
		
		if(seq == 20){
			++fl;
		}
		
		return fl;
	}
	
	public:int getNextSeq2CNES(char *cnes){
		int fl = 1;
		int seq = 1;
		
		for(int i = 0; i < lsz; i++){
			
			if(strcmp(list[i]->cnes, cnes) == 0){
				int cfl = atoi(list[i]->fl);
				int cseq = atoi(list[i]->seq);
				
				if(cfl > fl || (cfl == fl && cseq > seq)){
					fl = cfl;
					seq = cseq;
				}
			}
			
		}
		
		if(seq == 20){
			seq = 1;
		}
		else{
			++seq;
		}
		
		return seq;
	}
	
	public:void dropFormated2Excel(char *filename){
		FILE *f = fopen(filename, "wb");
		char s_header[5000];
		strcpy(s_header, "Tipo de registro\t");
		strcat(s_header, "CNES\t");
		strcat(s_header, "Competencia\t");
		strcat(s_header, "CBO\t");
		strcat(s_header, "Folha\t");
		strcat(s_header, "Sequencia\t");
		strcat(s_header, "Procedimento\t");
		strcat(s_header, "Idade\t");
		strcat(s_header, "Quantidade\t");
		strcat(s_header, "Origem");
		fprintf(f, "%s\r\n", s_header);
		
		for(int i = 0; i < lsz; i++){
			fprintf(f, "%s\r\n", list[i]->get2ExcelLine());
		}
		
		fclose(f);
	}
};

class BPABuilder{
	
	private:char *getHstr(){
		char line[3000];
		
		FILE *f = fopen("header.cfg", "r");
		fgets(line, 3000, f);
		
		while(line[strlen(line) - 1] == '\n' || line[strlen(line) - 1] == '\r'){
			line[strlen(line) - 1] = 0;
		}
		
		fclose(f);
		
		return line;
	}
	
	public: BPABuilder(char *filename, BPACList *bpac_list, BPAIList *bpai_list, char *cmpt){
		char s_header[1000];
		strcpy(s_header, getHstr());
		
		char lines[100];
		char aux[1000];
		sprintf(lines, "%d", bpai_list->lsz + bpac_list->lsz);
		while(strlen(lines) < 6){
			sprintf(aux, "0%s", lines);
			strcpy(lines, aux);
		}
		
		char folhas[100];
		sprintf(folhas, "%d", (bpai_list->getLoadedFls() + bpac_list->getLoadedFls()));
		while(strlen(folhas) < 6){
			sprintf(aux, "0%s", folhas);
			strcpy(folhas, aux);
		}
		
		char controle[100];
		unsigned long long int sum = bpai_list->getProcCodeSum() + bpac_list->getProcCodeSum() + bpai_list->getProcQtddSum() + bpac_list->getProcQtddSum();
		sum = sum % 1111;
		sum += 1111;
		
		sprintf(controle, "%llu", sum);
		
		char header[3000];
		sprintf(header, "01#BPA#%s%s%s%s%s", cmpt, lines, folhas, controle, s_header);
		
		FILE *f = fopen(filename, "wb");
		fprintf(f, "%s\r\n", header);
		
		for(int i = 0; i < bpac_list->lsz; i++){
			fprintf(f, "%s\r\n", bpac_list->list[i]->getLine());
		}
		
		for(int i = 0; i < bpai_list->lsz; i++){
			fprintf(f, "%s\r\n", bpai_list->list[i]->getLine());
		}
		
		fclose(f);
	}
};

