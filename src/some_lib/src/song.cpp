#include "song.h"

namespace jukebox {
	Song::Song(const nlohmann::json::value_type& song_json) :
		title{ song_json["Title"] },
		artist{ song_json["Artist"] },
		genre{ song_json["Genre"] },
		length{ song_json["Length"] },
		bpm{ song_json["BPM"] }
	{
	}
}
