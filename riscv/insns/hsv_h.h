require_extension('H');
require_novirt();
require_privilege(get_field(STATE.hstatus->read(), HSTATUS_HU) ? PRV_U : PRV_S);
MMU.guest_store<uint16_t>(RS1, RS2);
