void sim_kine2(){

o2::steer::MCKinematicsReader reader("o2sim", o2::steer::MCKinematicsReader::Mode::kMCKine);

// loop over all events in the file
for (int event = 0; event < reader.getNEvents(0); ++event) {
	std::cout << "Event n°" << event << endl;
  // get all Monte Carlo tracks for this event
  std::vector<o2::MCTrack> const& tracks = reader.getTracks(event);
  for (auto track : tracks){
	  if((tracks[track.getMotherTrackId()].GetPdgCode() == 541 && track.GetPdgCode() != 541) || (tracks[track.getMotherTrackId()].getMotherTrackId() == 541 && track.GetPdgCode() != 541)){
		std::cout << "\tParticle from B_c : " << track.GetPdgCode() << ", mother : "<< tracks[track.getMotherTrackId()].GetPdgCode() << ", daughters : " << tracks[track.getFirstDaughterTrackId()].GetPdgCode() << ", " << tracks[track.getLastDaughterTrackId()].GetPdgCode() << ", has hits : " << track.hasHits()<< ", y = " << track.GetRapidity() << ", status : " << track.getStatusCode() << endl;
	  cout << endl;
	  }
	  if((tracks[track.getMotherTrackId()].GetPdgCode() == 443) || (tracks[track.getMotherTrackId()].getMotherTrackId() == 443)){
		std::cout << "\tParticle from J/psi : " << track.GetPdgCode() << ", mother : "<< tracks[track.getMotherTrackId()].GetPdgCode() << ", daughters : " << tracks[track.getFirstDaughterTrackId()].GetPdgCode() << ", " << tracks[track.getLastDaughterTrackId()].GetPdgCode() << ", has hits : " << track.hasHits()<< ", y = " << track.GetRapidity() << ", status : " << track.getStatusCode() << endl;
	  }
  }
}

  // analyse tracks
}
