void sim_kine(){

o2::steer::MCKinematicsReader reader("o2sim", o2::steer::MCKinematicsReader::Mode::kMCKine);

// loop over all events in the file
for (int event = 0; event < reader.getNEvents(0); ++event) {
  std::cout << "Event n°" << event << endl;
  // get all Monte Carlo tracks for this event
  std::vector<o2::MCTrack> const& tracks = reader.getTracks(event);
  for (auto track : tracks){
	  if (track.GetPdgCode()==541 && tracks[track.getMotherTrackId()].GetPdgCode() != 541){
		std::cout << "B_c found" << endl;
		std::cout << "\t daughters : " << tracks[track.getFirstDaughterTrackId()].GetPdgCode() << ", " << tracks[track.getLastDaughterTrackId()].GetPdgCode() << ", has hits : " << track.hasHits()<< ", y = " << track.GetRapidity() << endl;
	  }
	  if (track.GetPdgCode()==443  && tracks[track.getMotherTrackId()].GetPdgCode() != 443 ){
		std::cout << "J/psi found" << endl;
		std::cout << "\t Status : " << track.getStatusCode() <<  " mother : " << tracks[track.getMotherTrackId()].GetPdgCode() << " daughters : " << tracks[track.getFirstDaughterTrackId()].GetPdgCode() << ", " << tracks[track.getLastDaughterTrackId()].GetPdgCode() << ", has hits : " << track.hasHits()<< ", y = " << track.GetRapidity() << endl;
	  }
  }

  // analyse tracks
}
}
