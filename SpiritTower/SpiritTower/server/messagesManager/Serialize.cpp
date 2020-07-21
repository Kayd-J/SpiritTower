#include "Serialize.h"

string Serialize::SerializeMatrix(std::string MatrixMap[20][20]) {
	json_object* jobj = json_object_new_object();
	json_object* jarray1 = json_object_new_array();

	for (int x = 0; x < 20; x++) {
		json_object* jarray2 = json_object_new_array();
		for (int y = 0; y < 20; y++) {
			const char* str1 = MatrixMap[x][y].c_str();
			json_object* jsonString = json_object_new_string(str1);
			json_object_array_add(jarray2, jsonString);
		}
		json_object_array_add(jarray1, jarray2);
	}
	//printf("The json object created: %s", json_object_to_json_string(jarray1));
	json_object_object_add(jobj, "Matrix", jarray1);
	string serialized = json_object_to_json_string(jobj);
	return serialized;
}
