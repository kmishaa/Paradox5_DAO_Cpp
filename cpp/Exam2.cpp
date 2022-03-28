#import <C:\Program Files (x86)\Common Files\Microsoft Shared\DAO\dao360.dll> rename( "EOF", "AdoNSEOF" )
#include <iostream>
int main()
{
//    std::cout << "Start";	
    CoInitialize(NULL);
//    std::cout << "1";
    DAO::DatabasePtr dbase;
//std::cout << "2";
    DAO::_TableDefPtr tblNew;
//std::cout << "3";
    DAO::_FieldPtr fldNew;
//std::cout << "4";
    DAO::_DBEnginePtr Dbe(__uuidof(DAO::DBEngine));
//	dbaseOpenDatabase("C:\DB\", 0, 0, "Paradox 5.x;UID="root";PWD="root";")
//std::cout << "5";
    dbase = Dbe->OpenDatabase(_bstr_t("C:\\DB\\"), 0, 0, _variant_t("Paradox 5.x;LANGID=0x0419;CP=1251;COUNTRY=0;"));
//std::cout << "6";
    tblNew = dbase->CreateTableDef(_variant_t("my_tbl"));
    tblNew->Fields->Append(tblNew->CreateField(_variant_t("field1"), _variant_t((short)DAO::dbInteger)));
    tblNew->Fields->Append(tblNew->CreateField(_variant_t("field2"), _variant_t((short)DAO::dbText), _variant_t((short)15)));
    tblNew->Fields->Append(tblNew->CreateField(_variant_t("field3"), _variant_t((short)DAO::dbInteger)));
    tblNew->Fields->Append(tblNew->CreateField(_variant_t("field4"), _variant_t((short)DAO::dbDouble)));
    dbase->TableDefs->Append(_variant_t((IDispatch*)tblNew));
    printf("Done with success!");
    dbase->Close();
    dbase = NULL;
    tblNew = NULL;
    std::cout << "End";
}